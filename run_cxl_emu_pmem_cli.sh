#!/bin/bash

readonly BASEDIR=$(readlink -f $(dirname $0))/../../

source "${BASEDIR}/script/common.sh"

QEMU_PATH=${BASEDIR}/lib/qemu/
QEMU_BUILD_PATH=${QEMU_PATH}/qemu-8.1.50/build/
IMAGE_PATH=~/images/u20s.qcow2
MONITOR_PORT=8080

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
    -nographic \
    -numa node,cpus=0-5,memdev=mem0,nodeid=0 \
    -object memory-backend-ram,id=mem0,size=8G \
    -m 8G,slots=8,maxmem=16G \
    -drive file=${IMAGE_PATH},format=qcow2 \
    -serial mon:stdio \
    -device e1000,netdev=net0 \
    -netdev user,id=net0,hostfwd=tcp::2242-:22 \
    -monitor telnet::${MONITOR_PORT},server,nowait \
    -machine q35,cxl=on \
    -M cxl-fmw.0.targets.0=cxl.1,cxl-fmw.0.size=16G \
    -object memory-backend-file,id=cxl-mem1,share=on,mem-path=/tmp/cxltest_p.raw,size=12G \
	-object memory-backend-file,id=cxl-lsa1,share=on,mem-path=/tmp/lsa_p2.raw,size=1G \
	-device pxb-cxl,bus_nr=12,bus=pcie.0,id=cxl.1 \
	-device cxl-rp,port=0,bus=cxl.1,id=root_port13,chassis=0,slot=2 \
	-device cxl-type3,bus=root_port13,persistent-memdev=cxl-mem1,lsa=cxl-lsa1,id=cxl-pmem0 