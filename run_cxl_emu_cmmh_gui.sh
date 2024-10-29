#!/bin/bash

readonly BASEDIR=$(readlink -f $(dirname $0))/../../

source "${BASEDIR}/script/common.sh"

# Configurable SSD Controller layout parameters (must be power of 2)
enable_gc_delay=1 # enable gc delay
enable_emu_delay=1
secsz=512 # sector size in bytes
secs_per_pg=8 # number of sectors in a flash page
pgs_per_blk=256 # number of pages per flash block
blks_per_pl=256 # number of blocks per plane
pls_per_lun=1 # keep it at one, no multiplanes support
luns_per_ch=8 # number of chips per channel
nchs=8 # number of channels
ssd_size=12288 # in megabytes, if you change the above layout parameters, make sure you manually recalculate the ssd size and modify it here, please consider a default 25% overprovisioning ratio.
# Configure Cache
# calculate cache size by parameters above
cache_index_bits=12
cache_num_tag=16

# Latency in nanoseconds
pg_rd_lat=40000 # page read latency
pg_wr_lat=200000 # page write latency
blk_er_lat=2000000 # block erase latency
ch_xfer_lat=0 # channel transfer time, ignored for now

# GC Threshold (1-100)
gc_thres_pcent=75
gc_thres_pcent_high=95

#-----------------------------------------------------------------------

#Compose the entire FEMU BBSSD command line options
FEMU_OPTIONS="-device cxl-type3 "
FEMU_OPTIONS=${FEMU_OPTIONS}",bus=root_port13 "
FEMU_OPTIONS=${FEMU_OPTIONS}",cmm-hybrid-memdev=cmmh0"
FEMU_OPTIONS=${FEMU_OPTIONS}",lsa=cxl-lsa1"
FEMU_OPTIONS=${FEMU_OPTIONS}",id=cxl-cmmh0"
FEMU_OPTIONS=${FEMU_OPTIONS}",devsz_mb=${ssd_size}"
FEMU_OPTIONS=${FEMU_OPTIONS}",namespaces=1"
FEMU_OPTIONS=${FEMU_OPTIONS}",femu_mode=1"
FEMU_OPTIONS=${FEMU_OPTIONS}",secsz=${secsz}"
FEMU_OPTIONS=${FEMU_OPTIONS}",secs_per_pg=${secs_per_pg}"
FEMU_OPTIONS=${FEMU_OPTIONS}",pgs_per_blk=${pgs_per_blk}"
FEMU_OPTIONS=${FEMU_OPTIONS}",blks_per_pl=${blks_per_pl}"
FEMU_OPTIONS=${FEMU_OPTIONS}",pls_per_lun=${pls_per_lun}"
FEMU_OPTIONS=${FEMU_OPTIONS}",luns_per_ch=${luns_per_ch}"
FEMU_OPTIONS=${FEMU_OPTIONS}",nchs=${nchs}"
FEMU_OPTIONS=${FEMU_OPTIONS}",pg_rd_lat=${pg_rd_lat}"
FEMU_OPTIONS=${FEMU_OPTIONS}",pg_wr_lat=${pg_wr_lat}"
FEMU_OPTIONS=${FEMU_OPTIONS}",blk_er_lat=${blk_er_lat}"
FEMU_OPTIONS=${FEMU_OPTIONS}",gc_thres_pcent=${gc_thres_pcent}"
FEMU_OPTIONS=${FEMU_OPTIONS}",gc_thres_pcent_high=${gc_thres_pcent_high}"
FEMU_OPTIONS=${FEMU_OPTIONS}",enable_gc_delay=${enable_gc_delay}"
FEMU_OPTIONS=${FEMU_OPTIONS}",enable_emu_delay=${enable_emu_delay}"
FEMU_OPTIONS=${FEMU_OPTIONS}",cache_index_bits=${cache_index_bits}"
FEMU_OPTIONS=${FEMU_OPTIONS}",cache_num_tag=${cache_num_tag}"

echo ${FEMU_OPTIONS}
QEMU_PATH=${BASEDIR}/lib/qemu/
QEMU_BUILD_PATH=${QEMU_PATH}/qemu-8.1.50/build/
IMAGE_PATH=${QEMU_PATH}/qemu-image-gui.img
MONITOR_PORT=45454

QEMU_SYSTEM_BINARY=${QEMU_BUILD_PATH}/qemu-system-x86_64

if [ ! -f "${QEMU_SYSTEM_BINARY}" ]; then
    log_error "qemu-system-x86_64 binary does not exist. Run 'build_lib.sh qemu' in /path/to/SMDK/lib/"
    exit 2
fi

if [ ! -f "${IMAGE_PATH}" ]; then
    log_error "QEMU image ${IMAGE_PATH} does not exist. Run 'create_gui_image.sh' and 'gui_setup_ssh.sh' in /path/to/SMDK/lib/"
    exit 2
fi

sudo ${QEMU_SYSTEM_BINARY} \
	-enable-kvm \
    -smp 6 \
    -numa node,cpus=0-5,memdev=mem0,nodeid=0 \
    -object memory-backend-ram,id=mem0,size=8G \
    -m 8G,slots=8,maxmem=16G \
    -drive file=${IMAGE_PATH},format=qcow2 \
    -serial mon:stdio \
    -device e1000,netdev=net0 \
    -netdev user,id=net0,hostfwd=tcp::2242-:22 \
    -monitor telnet::${MONITOR_PORT},server,nowait \
    -machine q35,cxl=on \
    -M cxl-fmw.0.targets.0=cxl.1,cxl-fmw.0.size=12G \
    -device pxb-cxl,bus_nr=12,bus=pcie.0,id=cxl.1 \
    -device cxl-rp,port=0,bus=cxl.1,id=root_port13,chassis=0,slot=2 \
    -object memory-backend-ram,id=cmmh0,share=on,size=12G \
    -object memory-backend-file,id=cxl-lsa1,share=on,mem-path=/tmp/lsa.raw,size=12G \
	${FEMU_OPTIONS} 
