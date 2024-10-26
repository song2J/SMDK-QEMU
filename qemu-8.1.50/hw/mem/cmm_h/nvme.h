#ifndef __FEMU_NVME_H
#define __FEMU_NVME_H

#include "qemu/osdep.h"
#include "qemu/uuid.h"
#include "qemu/units.h"
#include "qemu/cutils.h"
#include "qemu/memalign.h"
#include "hw/pci/msix.h"
#include "hw/pci/msi.h"
#include "hw/virtio/vhost.h"
#include "qapi/error.h"
#include "sysemu/kvm.h"

#include "inc/rte_ring.h"
#include "inc/pqueue.h"
#include "nand/nand.h"
#include "timing-model/timing.h"

#define NVME_SPARE_THRESHOLD    20
#define NVME_TEMPERATURE        0x143
#define NVME_OP_ABORTED         0xff
#define NVME_CMD_FLAGS_FUSE(flags) (flags & 0x3)
#define NVME_CMD_FLAGS_PSDT(flags) ((flags >> 6) & 0x3)


enum NvmeIoCommands {
    NVME_CMD_FLUSH              = 0x00,
    NVME_CMD_WRITE              = 0x01,
    NVME_CMD_READ               = 0x02,
    NVME_CMD_DSM                = 0x09,
};

typedef struct NvmeRequest {
    uint16_t                status;
    uint64_t                slba;
    uint16_t                is_write;
    uint16_t                nlb;
    uint8_t                 opcode;
    /* position in the priority queue for delay emulation */
    size_t                  pos;
} NvmeRequest;

#define TYPE_NVME "femu"
#define FEMU(obj) OBJECT_CHECK(FemuCtrl, (obj), TYPE_NVME)

/* do NOT go beyound 256 (uint8_t) */
#define FEMU_MAX_NUM_CHNLS (32)
#define FEMU_MAX_NUM_CHIPS (128)

typedef struct BbCtrlParams {
    int secsz;
    int secs_per_pg;
    int pgs_per_blk;
    int blks_per_pl;
    int pls_per_lun;
    int luns_per_ch;
    int nchs;

    int pg_rd_lat;
    int pg_wr_lat;
    int blk_er_lat;
    int ch_xfer_lat;

    int gc_thres_pcent;
    int gc_thres_pcent_high;
} BbCtrlParams;

typedef struct FemuCtrl {

    time_t      start_time;
    /* NEW features*/
    uint8_t     enable_gc_delay;
    uint8_t     enable_delay_emu;
    /********* */
    char            *serial;
    uint32_t        memsz;
    uint32_t    num_namespaces;
    uint8_t     lba_index;
    uint16_t    temperature;
    uint16_t    page_size;
    uint16_t    page_bits;
    uint32_t    reg_size;
    uint8_t     db_stride;
    uint16_t    vid;
    uint16_t    did;
    bool        dataplane_started;
    char            *logfile;
    BbCtrlParams bb_params;

    struct ssd      *ssd;
    int             completed;
    char            devname[64];

    int64_t         nr_tt_ios;
    int64_t         nr_tt_late_ios;
    bool            print_log;

    /* Nand Flash Type: SLC/MLC/TLC/QLC/PLC */
    uint8_t         flash_type;
    typedef struct flash_ops{
        void    (*cmd_to_req)(uint64_t, int, bool, NvmeRequest*);
        uin64_t (*ftl_io)(FemuCtrl*, NvmeRequest*);
        void    (*init)(FemuCtrl*);
    } flash_ops;

} FemuCtrl;

int cmmh_register_bb_flash_ops(FemuCtrl *n);

#define MN_MAX_LEN (64)
#define ID_MAX_LEN (4)

//#define FEMU_DEBUG_NVME
#ifdef FEMU_DEBUG_NVME
#define femu_debug(fmt, ...) \
    do { printf("[FEMU] Dbg: " fmt, ## __VA_ARGS__); } while (0)
#else
#define femu_debug(fmt, ...) \
    do { } while (0)
#endif

#define femu_err(fmt, ...) \
    do { fprintf(stderr, "[FEMU] Err: " fmt, ## __VA_ARGS__); } while (0)

#define femu_log(fmt, ...) \
    do { printf("[FEMU] Log: " fmt, ## __VA_ARGS__); } while (0)


#endif /* __FEMU_NVME_H */
