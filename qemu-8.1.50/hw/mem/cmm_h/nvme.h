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

#include "backend/dram.h"
#include "inc/rte_ring.h"
#include "inc/pqueue.h"
#include "nand/nand.h"
#include "timing-model/timing.h"

#define NVME_SPARE_THRESHOLD    20
#define NVME_TEMPERATURE        0x143
#define NVME_OP_ABORTED         0xff

enum NvmePsdt {
    NVME_PSDT_PRP                 = 0x0,
    NVME_PSDT_SGL_MPTR_CONTIGUOUS = 0x1,
    NVME_PSDT_SGL_MPTR_SGL        = 0x2,
};

typedef struct NvmeCmd {
    uint16_t    opcode : 8;
    uint16_t    fuse   : 2;
    uint16_t    res1   : 4;
    uint16_t    psdt   : 2;
    uint16_t    cid;
    uint32_t    nsid;
    uint64_t    res2;
    uint64_t    mptr;
    NvmeCmdDptr dptr;
    uint32_t    cdw10;
    uint32_t    cdw11;
    uint32_t    cdw12;
    uint32_t    cdw13;
    uint32_t    cdw14;
    uint32_t    cdw15;
} NvmeCmd;

#define NVME_CMD_FLAGS_FUSE(flags) (flags & 0x3)
#define NVME_CMD_FLAGS_PSDT(flags) ((flags >> 6) & 0x3)


enum NvmeIoCommands {
    NVME_CMD_FLUSH              = 0x00,
    NVME_CMD_WRITE              = 0x01,
    NVME_CMD_READ               = 0x02,
    NVME_CMD_DSM                = 0x09,
};


typedef struct NvmeIdentity {
    uint8_t     opcode;
    uint8_t     flags;
    uint16_t    cid;
    uint32_t    nsid;
    uint64_t    rsvd2[2];
    uint64_t    prp1;
    uint64_t    prp2;
    uint32_t    cns;
    uint16_t    nvmsetid;
    uint8_t     rsvd11;
    uint8_t     csi;
    uint32_t    rsvd12[4];
} NvmeIdentify;

typedef struct NvmeRwCmd {
    uint8_t     opcode;
    uint8_t     flags;
    uint16_t    cid;
    uint32_t    nsid;
    uint64_t    rsvd2;
    uint64_t    mptr;
    uint64_t    prp1;
    uint64_t    prp2;
    uint64_t    slba;
    uint16_t    nlb;
    uint16_t    control;
    uint32_t    dsmgmt;
    uint32_t    reftag;
    uint16_t    apptag;
    uint16_t    appmask;
} NvmeRwCmd;

enum NvmeStatusCodes {
    NVME_SUCCESS                = 0x0000,
    NVME_INVALID_OPCODE         = 0x0001,
    NVME_INVALID_FIELD          = 0x0002,
    NVME_CID_CONFLICT           = 0x0003,
    NVME_DATA_TRAS_ERROR        = 0x0004,
    NVME_POWER_LOSS_ABORT       = 0x0005,
    NVME_INTERNAL_DEV_ERROR     = 0x0006,
    NVME_CMD_ABORT_REQ          = 0x0007,
    NVME_CMD_ABORT_SQ_DEL       = 0x0008,
    NVME_CMD_ABORT_FAILED_FUSE  = 0x0009,
    NVME_CMD_ABORT_MISSING_FUSE = 0x000a,
    NVME_INVALID_NSID           = 0x000b,
    NVME_CMD_SEQ_ERROR          = 0x000c,
    NVME_INVALID_CMD_SET        = 0x002c,
    NVME_LBA_RANGE              = 0x0080,
    NVME_CAP_EXCEEDED           = 0x0081,
    NVME_NS_NOT_READY           = 0x0082,
    NVME_NS_RESV_CONFLICT       = 0x0083,
    NVME_INVALID_CQID           = 0x0100,
    NVME_INVALID_QID            = 0x0101,
    NVME_MAX_QSIZE_EXCEEDED     = 0x0102,
    NVME_ACL_EXCEEDED           = 0x0103,
    NVME_RESERVED               = 0x0104,
    NVME_AER_LIMIT_EXCEEDED     = 0x0105,
    NVME_INVALID_FW_SLOT        = 0x0106,
    NVME_INVALID_FW_IMAGE       = 0x0107,
    NVME_INVALID_IRQ_VECTOR     = 0x0108,
    NVME_INVALID_LOG_ID         = 0x0109,
    NVME_INVALID_FORMAT         = 0x010a,
    NVME_FW_REQ_RESET           = 0x010b,
    NVME_INVALID_QUEUE_DEL      = 0x010c,
    NVME_FID_NOT_SAVEABLE       = 0x010d,
    NVME_FID_NOT_NSID_SPEC      = 0x010f,
    NVME_FW_REQ_SUSYSTEM_RESET  = 0x0110,
    NVME_CONFLICTING_ATTRS      = 0x0180,
    NVME_INVALID_PROT_INFO      = 0x0181,
    NVME_WRITE_TO_RO            = 0x0182,
    NVME_ZONE_BOUNDARY_ERROR    = 0x01b8,
    NVME_ZONE_FULL              = 0x01b9,
    NVME_ZONE_READ_ONLY         = 0x01ba,
    NVME_ZONE_OFFLINE           = 0x01bb,
    NVME_ZONE_INVALID_WRITE     = 0x01bc,
    NVME_ZONE_TOO_MANY_ACTIVE   = 0x01bd,
    NVME_ZONE_TOO_MANY_OPEN     = 0x01be,
    NVME_ZONE_INVAL_TRANSITION  = 0x01bf,
    NVME_INVALID_MEMORY_ADDRESS = 0x01C0,
    NVME_WRITE_FAULT            = 0x0280,
    NVME_UNRECOVERED_READ       = 0x0281,
    NVME_E2E_GUARD_ERROR        = 0x0282,
    NVME_E2E_APP_ERROR          = 0x0283,
    NVME_E2E_REF_ERROR          = 0x0284,
    NVME_CMP_FAILURE            = 0x0285,
    NVME_ACCESS_DENIED          = 0x0286,
    NVME_DULB                   = 0x0287,
    NVME_MORE                   = 0x2000,
    NVME_DNR                    = 0x4000,
    NVME_NO_COMPLETE            = 0xffff,
};

#define NVME_NSID_BROADCAST 0xffffffff

static inline void nvme_check_size(void)
{
    QEMU_BUILD_BUG_ON(sizeof(NvmeCmd) != 64);
    QEMU_BUILD_BUG_ON(sizeof(NvmeIdentify) != 64);
    QEMU_BUILD_BUG_ON(sizeof(NvmeRwCmd) != 64);
}
typedef struct NvmeRequest {
    uint16_t                status;
    uint64_t                slba;
    uint16_t                is_write;
    uint16_t                nlb;
    uint16_t                ctrl;
    uint64_t                meta_size;
    uint64_t                mptr;
    void                    *meta_buf;
    NvmeCmd                 cmd;
    uint8_t                 cmd_opcode;
    QEMUSGList              qsg;
    QEMUIOVector            iov;
    int64_t                 stime;
    int64_t                 reqlat;
    int64_t                 gcrt;
    int64_t                 expire_time;

    /* OC2.0: sector offset relative to slba where reads become invalid */
    uint64_t predef;

    /* ZNS */
    void                    *opaque;

    /* position in the priority queue for delay emulation */
    size_t                  pos;
} NvmeRequest;


typedef struct NvmeIdNsZoned NvmeIdNsZoned;
typedef struct NvmeZone NvmeZone;

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
    NvmeRequest     **aer_reqs;
    QEMUTimer       *aer_timer;
    uint8_t         aer_mask;

    BbCtrlParams bb_params;

    struct ssd      *ssd;
    int             completed;

    char            devname[64];

    int64_t         nr_tt_ios;
    int64_t         nr_tt_late_ios;
    bool            print_log;

    uint8_t         multipoller_enabled;
    uint32_t        nr_pollers;

    /* Nand Flash Type: SLC/MLC/TLC/QLC/PLC */
    uint8_t         flash_type;
    typedef struct FlashOps{
        void    (*cmd_to_req)(uint16_t, uint64_t, int, NvmeRequest*);
        uin64_t (*ftl_io)(FemuCtrl*, NvmeRequest*);
        void    (*init)(FemuCtrl*);
    } FlashOps;

} FemuCtrl;


enum {
    FEMU_BBSSD_MODE = 1,
};

static inline bool BBSSD(FemuCtrl *n)
{
    return (n->femu_mode == FEMU_BBSSD_MODE);
}


/* NVMe I/O */
uint16_t nvme_rw(FemuCtrl *n, NvmeNamespace *ns, NvmeCmd *cmd, NvmeRequest *req);

int cmmh_register_bb_flashOps(FemuCtrl *n);

/*static inline uint64_t ns_blks(NvmeNamespace *ns, uint8_t lba_idx)
{
    FemuCtrl *n = ns->ctrl;
    uint64_t ns_size = n->ns_size;

    uint32_t lba_ds = (1 << id_ns->lbaf[lba_idx].lbads);
    uint32_t lba_sz = lba_ds + n->meta;

    return ns_size / lba_sz;
}
static inline hwaddr nvme_discontig(uint64_t *dma_addr, uint16_t queue_idx,
                                    uint16_t page_size, uint16_t entry_size)
{
    uint16_t entries_per_page = page_size / entry_size;
    uint16_t prp_index = queue_idx / entries_per_page;
    uint16_t index_in_prp = queue_idx % entries_per_page;

    return dma_addr[prp_index] + index_in_prp * entry_size;
}

static inline uint16_t nvme_check_mdts(FemuCtrl *n, size_t len)
{
    uint8_t mdts = n->mdts;

    if (mdts && len > n->page_size << mdts) {
        return NVME_INVALID_FIELD | NVME_DNR;
    }

    return NVME_SUCCESS;
}
*/

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
