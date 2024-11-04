#ifndef __CMMH_H
#define __CMMH_H

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
//#include "timing-model/timing.h"

#define CMMH_SPARE_THRESHOLD    20
#define CMMH_TEMPERATURE        0x143
#define CMMH_OP_ABORTED         0xff
#define CMMH_CMD_FLAGS_FUSE(flags) (flags & 0x3)
#define CMMH_CMD_FLAGS_PSDT(flags) ((flags >> 6) & 0x3)


enum CMMHFlashIoCommands {
    CMMH_FLASH_CMD_FLUSH              = 0x00,
    CMMH_FLASH_CMD_WRITE              = 0x01,
    CMMH_FLASH_CMD_READ               = 0x02,
    CMMH_FLASH_CMD_DSM                = 0x09,
};

typedef struct CMMHFlashRequest {
    uint16_t                status;
    uint64_t                slba;
    uint16_t                is_write;
    uint16_t                nlb;
    uint8_t                 opcode;
    /* position in the priority queue for delay emulation */
    size_t                  pos;
    int64_t                 stime;
} CMMHFlashRequest;

/* do NOT go beyound 256 (uint8_t) */
#define CMMH_FLASH_MAX_NUM_CHNLS (32)
#define CMMH_FLASH_MAX_NUM_CHIPS (128)

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

typedef struct CMMHFlashCtrl {

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
    struct {
        uint64_t    (*ftl_io)(struct CMMHFlashCtrl*, uint64_t, int, bool);
        void        (*init)(struct CMMHFlashCtrl*);
    } flash_ops;


} CMMHFlashCtrl;

extern void cmmh_register_bb_flash_ops(CMMHFlashCtrl* n);

#define MN_MAX_LEN (64)
#define ID_MAX_LEN (4)

//#define CMMH_DEBUG_NVME
#ifdef CMMH_DEBUG_NVME
#define cmmh_debug(fmt, ...) \
    do { printf("[CMMH] Dbg: " fmt, ## __VA_ARGS__); } while (0)
#else
#define cmmh_debug(fmt, ...) \
    do { } while (0)
#endif

#define cmmh_err(fmt, ...) \
    do { fprintf(stderr, "[CMMH] Err: " fmt, ## __VA_ARGS__); } while (0)

#define cmmh_log(fmt, ...) \
    do { printf("[CMMH] Log: " fmt, ## __VA_ARGS__); } while (0)


#endif /* __CMMH_NVME_H */
