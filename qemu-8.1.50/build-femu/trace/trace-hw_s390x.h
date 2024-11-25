/* This file is autogenerated by tracetool, do not edit. */

#ifndef TRACE_HW_S390X_GENERATED_TRACERS_H
#define TRACE_HW_S390X_GENERATED_TRACERS_H

#include "trace/control.h"

extern TraceEvent _TRACE_CSS_ENABLE_FACILITY_EVENT;
extern TraceEvent _TRACE_CSS_CRW_EVENT;
extern TraceEvent _TRACE_CSS_CHPID_ADD_EVENT;
extern TraceEvent _TRACE_CSS_NEW_IMAGE_EVENT;
extern TraceEvent _TRACE_CSS_ASSIGN_SUBCH_EVENT;
extern TraceEvent _TRACE_CSS_IO_INTERRUPT_EVENT;
extern TraceEvent _TRACE_CSS_ADAPTER_INTERRUPT_EVENT;
extern TraceEvent _TRACE_CSS_DO_SIC_EVENT;
extern TraceEvent _TRACE_VIRTIO_CCW_INTERPRET_CCW_EVENT;
extern TraceEvent _TRACE_VIRTIO_CCW_NEW_DEVICE_EVENT;
extern TraceEvent _TRACE_VIRTIO_CCW_SET_IND_EVENT;
extern TraceEvent _TRACE_S390_PCI_CLP_CAP_EVENT;
extern TraceEvent _TRACE_S390_PCI_CLP_CAP_SIZE_EVENT;
extern TraceEvent _TRACE_S390_PCI_CLP_DEV_INFO_EVENT;
extern TraceEvent _TRACE_S390_PCI_SCLP_NODEV_EVENT;
extern TraceEvent _TRACE_S390_PCI_IOMMU_XLATE_EVENT;
extern TraceEvent _TRACE_S390_PCI_MSI_CTRL_WRITE_EVENT;
extern TraceEvent _TRACE_S390_PCIHOST_EVENT;
extern TraceEvent _TRACE_S390_PCI_IRQS_EVENT;
extern TraceEvent _TRACE_S390_PCI_KVM_AIF_EVENT;
extern TraceEvent _TRACE_S390_PCI_LIST_ENTRY_EVENT;
extern TraceEvent _TRACE_S390_PCI_LIST_EVENT;
extern TraceEvent _TRACE_S390_PCI_UNKNOWN_EVENT;
extern TraceEvent _TRACE_S390_PCI_BAR_EVENT;
extern TraceEvent _TRACE_S390_PCI_NODEV_EVENT;
extern TraceEvent _TRACE_S390_PCI_INVALID_EVENT;
extern uint16_t _TRACE_CSS_ENABLE_FACILITY_DSTATE;
extern uint16_t _TRACE_CSS_CRW_DSTATE;
extern uint16_t _TRACE_CSS_CHPID_ADD_DSTATE;
extern uint16_t _TRACE_CSS_NEW_IMAGE_DSTATE;
extern uint16_t _TRACE_CSS_ASSIGN_SUBCH_DSTATE;
extern uint16_t _TRACE_CSS_IO_INTERRUPT_DSTATE;
extern uint16_t _TRACE_CSS_ADAPTER_INTERRUPT_DSTATE;
extern uint16_t _TRACE_CSS_DO_SIC_DSTATE;
extern uint16_t _TRACE_VIRTIO_CCW_INTERPRET_CCW_DSTATE;
extern uint16_t _TRACE_VIRTIO_CCW_NEW_DEVICE_DSTATE;
extern uint16_t _TRACE_VIRTIO_CCW_SET_IND_DSTATE;
extern uint16_t _TRACE_S390_PCI_CLP_CAP_DSTATE;
extern uint16_t _TRACE_S390_PCI_CLP_CAP_SIZE_DSTATE;
extern uint16_t _TRACE_S390_PCI_CLP_DEV_INFO_DSTATE;
extern uint16_t _TRACE_S390_PCI_SCLP_NODEV_DSTATE;
extern uint16_t _TRACE_S390_PCI_IOMMU_XLATE_DSTATE;
extern uint16_t _TRACE_S390_PCI_MSI_CTRL_WRITE_DSTATE;
extern uint16_t _TRACE_S390_PCIHOST_DSTATE;
extern uint16_t _TRACE_S390_PCI_IRQS_DSTATE;
extern uint16_t _TRACE_S390_PCI_KVM_AIF_DSTATE;
extern uint16_t _TRACE_S390_PCI_LIST_ENTRY_DSTATE;
extern uint16_t _TRACE_S390_PCI_LIST_DSTATE;
extern uint16_t _TRACE_S390_PCI_UNKNOWN_DSTATE;
extern uint16_t _TRACE_S390_PCI_BAR_DSTATE;
extern uint16_t _TRACE_S390_PCI_NODEV_DSTATE;
extern uint16_t _TRACE_S390_PCI_INVALID_DSTATE;
#define TRACE_CSS_ENABLE_FACILITY_ENABLED 1
#define TRACE_CSS_CRW_ENABLED 1
#define TRACE_CSS_CHPID_ADD_ENABLED 1
#define TRACE_CSS_NEW_IMAGE_ENABLED 1
#define TRACE_CSS_ASSIGN_SUBCH_ENABLED 1
#define TRACE_CSS_IO_INTERRUPT_ENABLED 1
#define TRACE_CSS_ADAPTER_INTERRUPT_ENABLED 1
#define TRACE_CSS_DO_SIC_ENABLED 1
#define TRACE_VIRTIO_CCW_INTERPRET_CCW_ENABLED 1
#define TRACE_VIRTIO_CCW_NEW_DEVICE_ENABLED 1
#define TRACE_VIRTIO_CCW_SET_IND_ENABLED 1
#define TRACE_S390_PCI_CLP_CAP_ENABLED 1
#define TRACE_S390_PCI_CLP_CAP_SIZE_ENABLED 1
#define TRACE_S390_PCI_CLP_DEV_INFO_ENABLED 1
#define TRACE_S390_PCI_SCLP_NODEV_ENABLED 1
#define TRACE_S390_PCI_IOMMU_XLATE_ENABLED 1
#define TRACE_S390_PCI_MSI_CTRL_WRITE_ENABLED 1
#define TRACE_S390_PCIHOST_ENABLED 1
#define TRACE_S390_PCI_IRQS_ENABLED 1
#define TRACE_S390_PCI_KVM_AIF_ENABLED 1
#define TRACE_S390_PCI_LIST_ENTRY_ENABLED 1
#define TRACE_S390_PCI_LIST_ENABLED 1
#define TRACE_S390_PCI_UNKNOWN_ENABLED 1
#define TRACE_S390_PCI_BAR_ENABLED 1
#define TRACE_S390_PCI_NODEV_ENABLED 1
#define TRACE_S390_PCI_INVALID_ENABLED 1
#include "qemu/log-for-trace.h"
#include "qemu/error-report.h"


#define TRACE_CSS_ENABLE_FACILITY_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_CSS_ENABLE_FACILITY) || \
    false)

static inline void _nocheck__trace_css_enable_facility(const char * facility)
{
    if (trace_event_get_state(TRACE_CSS_ENABLE_FACILITY) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 4 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:css_enable_facility " "CSS: enable %s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , facility);
#line 106 "trace/trace-hw_s390x.h"
        } else {
#line 4 "../hw/s390x/trace-events"
            qemu_log("css_enable_facility " "CSS: enable %s" "\n", facility);
#line 110 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_css_enable_facility(const char * facility)
{
    if (true) {
        _nocheck__trace_css_enable_facility(facility);
    }
}

#define TRACE_CSS_CRW_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_CSS_CRW) || \
    false)

static inline void _nocheck__trace_css_crw(uint8_t rsc, uint8_t erc, uint16_t rsid, const char * chained)
{
    if (trace_event_get_state(TRACE_CSS_CRW) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 5 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:css_crw " "CSS: queueing crw: rsc=0x%x, erc=0x%x, rsid=0x%x %s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , rsc, erc, rsid, chained);
#line 137 "trace/trace-hw_s390x.h"
        } else {
#line 5 "../hw/s390x/trace-events"
            qemu_log("css_crw " "CSS: queueing crw: rsc=0x%x, erc=0x%x, rsid=0x%x %s" "\n", rsc, erc, rsid, chained);
#line 141 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_css_crw(uint8_t rsc, uint8_t erc, uint16_t rsid, const char * chained)
{
    if (true) {
        _nocheck__trace_css_crw(rsc, erc, rsid, chained);
    }
}

#define TRACE_CSS_CHPID_ADD_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_CSS_CHPID_ADD) || \
    false)

static inline void _nocheck__trace_css_chpid_add(uint8_t cssid, uint8_t chpid, uint8_t type)
{
    if (trace_event_get_state(TRACE_CSS_CHPID_ADD) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 6 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:css_chpid_add " "CSS: add chpid %x.%02x (type 0x%02x)" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , cssid, chpid, type);
#line 168 "trace/trace-hw_s390x.h"
        } else {
#line 6 "../hw/s390x/trace-events"
            qemu_log("css_chpid_add " "CSS: add chpid %x.%02x (type 0x%02x)" "\n", cssid, chpid, type);
#line 172 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_css_chpid_add(uint8_t cssid, uint8_t chpid, uint8_t type)
{
    if (true) {
        _nocheck__trace_css_chpid_add(cssid, chpid, type);
    }
}

#define TRACE_CSS_NEW_IMAGE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_CSS_NEW_IMAGE) || \
    false)

static inline void _nocheck__trace_css_new_image(uint8_t cssid, const char * default_cssid)
{
    if (trace_event_get_state(TRACE_CSS_NEW_IMAGE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 7 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:css_new_image " "CSS: add css image 0x%02x %s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , cssid, default_cssid);
#line 199 "trace/trace-hw_s390x.h"
        } else {
#line 7 "../hw/s390x/trace-events"
            qemu_log("css_new_image " "CSS: add css image 0x%02x %s" "\n", cssid, default_cssid);
#line 203 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_css_new_image(uint8_t cssid, const char * default_cssid)
{
    if (true) {
        _nocheck__trace_css_new_image(cssid, default_cssid);
    }
}

#define TRACE_CSS_ASSIGN_SUBCH_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_CSS_ASSIGN_SUBCH) || \
    false)

static inline void _nocheck__trace_css_assign_subch(const char * do_assign, uint8_t cssid, uint8_t ssid, uint16_t schid, uint16_t devno)
{
    if (trace_event_get_state(TRACE_CSS_ASSIGN_SUBCH) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 8 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:css_assign_subch " "CSS: %s %x.%x.%04x (devno 0x%04x)" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , do_assign, cssid, ssid, schid, devno);
#line 230 "trace/trace-hw_s390x.h"
        } else {
#line 8 "../hw/s390x/trace-events"
            qemu_log("css_assign_subch " "CSS: %s %x.%x.%04x (devno 0x%04x)" "\n", do_assign, cssid, ssid, schid, devno);
#line 234 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_css_assign_subch(const char * do_assign, uint8_t cssid, uint8_t ssid, uint16_t schid, uint16_t devno)
{
    if (true) {
        _nocheck__trace_css_assign_subch(do_assign, cssid, ssid, schid, devno);
    }
}

#define TRACE_CSS_IO_INTERRUPT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_CSS_IO_INTERRUPT) || \
    false)

static inline void _nocheck__trace_css_io_interrupt(int cssid, int ssid, int schid, uint32_t intparm, uint8_t isc, const char * conditional)
{
    if (trace_event_get_state(TRACE_CSS_IO_INTERRUPT) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 9 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:css_io_interrupt " "CSS: I/O interrupt on sch %x.%x.%04x (intparm 0x%08x, isc 0x%x) %s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , cssid, ssid, schid, intparm, isc, conditional);
#line 261 "trace/trace-hw_s390x.h"
        } else {
#line 9 "../hw/s390x/trace-events"
            qemu_log("css_io_interrupt " "CSS: I/O interrupt on sch %x.%x.%04x (intparm 0x%08x, isc 0x%x) %s" "\n", cssid, ssid, schid, intparm, isc, conditional);
#line 265 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_css_io_interrupt(int cssid, int ssid, int schid, uint32_t intparm, uint8_t isc, const char * conditional)
{
    if (true) {
        _nocheck__trace_css_io_interrupt(cssid, ssid, schid, intparm, isc, conditional);
    }
}

#define TRACE_CSS_ADAPTER_INTERRUPT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_CSS_ADAPTER_INTERRUPT) || \
    false)

static inline void _nocheck__trace_css_adapter_interrupt(uint8_t isc)
{
    if (trace_event_get_state(TRACE_CSS_ADAPTER_INTERRUPT) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 10 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:css_adapter_interrupt " "CSS: adapter I/O interrupt (isc 0x%x)" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , isc);
#line 292 "trace/trace-hw_s390x.h"
        } else {
#line 10 "../hw/s390x/trace-events"
            qemu_log("css_adapter_interrupt " "CSS: adapter I/O interrupt (isc 0x%x)" "\n", isc);
#line 296 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_css_adapter_interrupt(uint8_t isc)
{
    if (true) {
        _nocheck__trace_css_adapter_interrupt(isc);
    }
}

#define TRACE_CSS_DO_SIC_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_CSS_DO_SIC) || \
    false)

static inline void _nocheck__trace_css_do_sic(uint16_t mode, uint8_t isc)
{
    if (trace_event_get_state(TRACE_CSS_DO_SIC) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 11 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:css_do_sic " "CSS: set interruption mode 0x%x on isc 0x%x" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , mode, isc);
#line 323 "trace/trace-hw_s390x.h"
        } else {
#line 11 "../hw/s390x/trace-events"
            qemu_log("css_do_sic " "CSS: set interruption mode 0x%x on isc 0x%x" "\n", mode, isc);
#line 327 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_css_do_sic(uint16_t mode, uint8_t isc)
{
    if (true) {
        _nocheck__trace_css_do_sic(mode, isc);
    }
}

#define TRACE_VIRTIO_CCW_INTERPRET_CCW_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_VIRTIO_CCW_INTERPRET_CCW) || \
    false)

static inline void _nocheck__trace_virtio_ccw_interpret_ccw(int cssid, int ssid, int schid, int cmd_code)
{
    if (trace_event_get_state(TRACE_VIRTIO_CCW_INTERPRET_CCW) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 14 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:virtio_ccw_interpret_ccw " "VIRTIO-CCW: %x.%x.%04x: interpret command 0x%x" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , cssid, ssid, schid, cmd_code);
#line 354 "trace/trace-hw_s390x.h"
        } else {
#line 14 "../hw/s390x/trace-events"
            qemu_log("virtio_ccw_interpret_ccw " "VIRTIO-CCW: %x.%x.%04x: interpret command 0x%x" "\n", cssid, ssid, schid, cmd_code);
#line 358 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_virtio_ccw_interpret_ccw(int cssid, int ssid, int schid, int cmd_code)
{
    if (true) {
        _nocheck__trace_virtio_ccw_interpret_ccw(cssid, ssid, schid, cmd_code);
    }
}

#define TRACE_VIRTIO_CCW_NEW_DEVICE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_VIRTIO_CCW_NEW_DEVICE) || \
    false)

static inline void _nocheck__trace_virtio_ccw_new_device(int cssid, int ssid, int schid, int devno, const char * devno_mode)
{
    if (trace_event_get_state(TRACE_VIRTIO_CCW_NEW_DEVICE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 15 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:virtio_ccw_new_device " "VIRTIO-CCW: add subchannel %x.%x.%04x, devno 0x%04x (%s)" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , cssid, ssid, schid, devno, devno_mode);
#line 385 "trace/trace-hw_s390x.h"
        } else {
#line 15 "../hw/s390x/trace-events"
            qemu_log("virtio_ccw_new_device " "VIRTIO-CCW: add subchannel %x.%x.%04x, devno 0x%04x (%s)" "\n", cssid, ssid, schid, devno, devno_mode);
#line 389 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_virtio_ccw_new_device(int cssid, int ssid, int schid, int devno, const char * devno_mode)
{
    if (true) {
        _nocheck__trace_virtio_ccw_new_device(cssid, ssid, schid, devno, devno_mode);
    }
}

#define TRACE_VIRTIO_CCW_SET_IND_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_VIRTIO_CCW_SET_IND) || \
    false)

static inline void _nocheck__trace_virtio_ccw_set_ind(uint64_t ind_loc, uint8_t ind_old, uint8_t ind_new)
{
    if (trace_event_get_state(TRACE_VIRTIO_CCW_SET_IND) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 16 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:virtio_ccw_set_ind " "VIRTIO-CCW: indicator at %" PRIu64 ": 0x%x->0x%x" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , ind_loc, ind_old, ind_new);
#line 416 "trace/trace-hw_s390x.h"
        } else {
#line 16 "../hw/s390x/trace-events"
            qemu_log("virtio_ccw_set_ind " "VIRTIO-CCW: indicator at %" PRIu64 ": 0x%x->0x%x" "\n", ind_loc, ind_old, ind_new);
#line 420 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_virtio_ccw_set_ind(uint64_t ind_loc, uint8_t ind_old, uint8_t ind_new)
{
    if (true) {
        _nocheck__trace_virtio_ccw_set_ind(ind_loc, ind_old, ind_new);
    }
}

#define TRACE_S390_PCI_CLP_CAP_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_S390_PCI_CLP_CAP) || \
    false)

static inline void _nocheck__trace_s390_pci_clp_cap(const char * id, uint32_t cap)
{
    if (trace_event_get_state(TRACE_S390_PCI_CLP_CAP) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 19 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:s390_pci_clp_cap " "PCI: %s: missing expected CLP capability %u" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , id, cap);
#line 447 "trace/trace-hw_s390x.h"
        } else {
#line 19 "../hw/s390x/trace-events"
            qemu_log("s390_pci_clp_cap " "PCI: %s: missing expected CLP capability %u" "\n", id, cap);
#line 451 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_s390_pci_clp_cap(const char * id, uint32_t cap)
{
    if (true) {
        _nocheck__trace_s390_pci_clp_cap(id, cap);
    }
}

#define TRACE_S390_PCI_CLP_CAP_SIZE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_S390_PCI_CLP_CAP_SIZE) || \
    false)

static inline void _nocheck__trace_s390_pci_clp_cap_size(const char * id, uint32_t size, uint32_t cap)
{
    if (trace_event_get_state(TRACE_S390_PCI_CLP_CAP_SIZE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 20 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:s390_pci_clp_cap_size " "PCI: %s: bad size (%u) for CLP capability %u" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , id, size, cap);
#line 478 "trace/trace-hw_s390x.h"
        } else {
#line 20 "../hw/s390x/trace-events"
            qemu_log("s390_pci_clp_cap_size " "PCI: %s: bad size (%u) for CLP capability %u" "\n", id, size, cap);
#line 482 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_s390_pci_clp_cap_size(const char * id, uint32_t size, uint32_t cap)
{
    if (true) {
        _nocheck__trace_s390_pci_clp_cap_size(id, size, cap);
    }
}

#define TRACE_S390_PCI_CLP_DEV_INFO_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_S390_PCI_CLP_DEV_INFO) || \
    false)

static inline void _nocheck__trace_s390_pci_clp_dev_info(const char * id)
{
    if (trace_event_get_state(TRACE_S390_PCI_CLP_DEV_INFO) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 21 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:s390_pci_clp_dev_info " "PCI: %s: cannot read vfio device info" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , id);
#line 509 "trace/trace-hw_s390x.h"
        } else {
#line 21 "../hw/s390x/trace-events"
            qemu_log("s390_pci_clp_dev_info " "PCI: %s: cannot read vfio device info" "\n", id);
#line 513 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_s390_pci_clp_dev_info(const char * id)
{
    if (true) {
        _nocheck__trace_s390_pci_clp_dev_info(id);
    }
}

#define TRACE_S390_PCI_SCLP_NODEV_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_S390_PCI_SCLP_NODEV) || \
    false)

static inline void _nocheck__trace_s390_pci_sclp_nodev(const char * str, uint32_t aid)
{
    if (trace_event_get_state(TRACE_S390_PCI_SCLP_NODEV) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 24 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:s390_pci_sclp_nodev " "%s no dev found aid 0x%x" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , str, aid);
#line 540 "trace/trace-hw_s390x.h"
        } else {
#line 24 "../hw/s390x/trace-events"
            qemu_log("s390_pci_sclp_nodev " "%s no dev found aid 0x%x" "\n", str, aid);
#line 544 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_s390_pci_sclp_nodev(const char * str, uint32_t aid)
{
    if (true) {
        _nocheck__trace_s390_pci_sclp_nodev(str, aid);
    }
}

#define TRACE_S390_PCI_IOMMU_XLATE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_S390_PCI_IOMMU_XLATE) || \
    false)

static inline void _nocheck__trace_s390_pci_iommu_xlate(uint64_t addr)
{
    if (trace_event_get_state(TRACE_S390_PCI_IOMMU_XLATE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 25 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:s390_pci_iommu_xlate " "iommu trans addr 0x%" PRIx64 "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , addr);
#line 571 "trace/trace-hw_s390x.h"
        } else {
#line 25 "../hw/s390x/trace-events"
            qemu_log("s390_pci_iommu_xlate " "iommu trans addr 0x%" PRIx64 "\n", addr);
#line 575 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_s390_pci_iommu_xlate(uint64_t addr)
{
    if (true) {
        _nocheck__trace_s390_pci_iommu_xlate(addr);
    }
}

#define TRACE_S390_PCI_MSI_CTRL_WRITE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_S390_PCI_MSI_CTRL_WRITE) || \
    false)

static inline void _nocheck__trace_s390_pci_msi_ctrl_write(uint64_t data, uint32_t idx, uint32_t vec)
{
    if (trace_event_get_state(TRACE_S390_PCI_MSI_CTRL_WRITE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 26 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:s390_pci_msi_ctrl_write " "write_msix data 0x%" PRIx64 " idx %d vec 0x%x" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , data, idx, vec);
#line 602 "trace/trace-hw_s390x.h"
        } else {
#line 26 "../hw/s390x/trace-events"
            qemu_log("s390_pci_msi_ctrl_write " "write_msix data 0x%" PRIx64 " idx %d vec 0x%x" "\n", data, idx, vec);
#line 606 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_s390_pci_msi_ctrl_write(uint64_t data, uint32_t idx, uint32_t vec)
{
    if (true) {
        _nocheck__trace_s390_pci_msi_ctrl_write(data, idx, vec);
    }
}

#define TRACE_S390_PCIHOST_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_S390_PCIHOST) || \
    false)

static inline void _nocheck__trace_s390_pcihost(const char * msg)
{
    if (trace_event_get_state(TRACE_S390_PCIHOST) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 27 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:s390_pcihost " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , msg);
#line 633 "trace/trace-hw_s390x.h"
        } else {
#line 27 "../hw/s390x/trace-events"
            qemu_log("s390_pcihost " "%s" "\n", msg);
#line 637 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_s390_pcihost(const char * msg)
{
    if (true) {
        _nocheck__trace_s390_pcihost(msg);
    }
}

#define TRACE_S390_PCI_IRQS_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_S390_PCI_IRQS) || \
    false)

static inline void _nocheck__trace_s390_pci_irqs(const char * str, uint32_t id)
{
    if (trace_event_get_state(TRACE_S390_PCI_IRQS) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 30 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:s390_pci_irqs " "%s irqs for adapter id %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , str, id);
#line 664 "trace/trace-hw_s390x.h"
        } else {
#line 30 "../hw/s390x/trace-events"
            qemu_log("s390_pci_irqs " "%s irqs for adapter id %d" "\n", str, id);
#line 668 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_s390_pci_irqs(const char * str, uint32_t id)
{
    if (true) {
        _nocheck__trace_s390_pci_irqs(str, id);
    }
}

#define TRACE_S390_PCI_KVM_AIF_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_S390_PCI_KVM_AIF) || \
    false)

static inline void _nocheck__trace_s390_pci_kvm_aif(const char * str)
{
    if (trace_event_get_state(TRACE_S390_PCI_KVM_AIF) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 31 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:s390_pci_kvm_aif " "Failed to %s interrupt forwarding" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , str);
#line 695 "trace/trace-hw_s390x.h"
        } else {
#line 31 "../hw/s390x/trace-events"
            qemu_log("s390_pci_kvm_aif " "Failed to %s interrupt forwarding" "\n", str);
#line 699 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_s390_pci_kvm_aif(const char * str)
{
    if (true) {
        _nocheck__trace_s390_pci_kvm_aif(str);
    }
}

#define TRACE_S390_PCI_LIST_ENTRY_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_S390_PCI_LIST_ENTRY) || \
    false)

static inline void _nocheck__trace_s390_pci_list_entry(uint32_t g_l2, uint32_t vid, uint32_t did, uint32_t fid, uint32_t fh)
{
    if (trace_event_get_state(TRACE_S390_PCI_LIST_ENTRY) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 33 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:s390_pci_list_entry " "g_l2 %d vendor id 0x%x device id 0x%x fid 0x%x fh 0x%x" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , g_l2, vid, did, fid, fh);
#line 726 "trace/trace-hw_s390x.h"
        } else {
#line 33 "../hw/s390x/trace-events"
            qemu_log("s390_pci_list_entry " "g_l2 %d vendor id 0x%x device id 0x%x fid 0x%x fh 0x%x" "\n", g_l2, vid, did, fid, fh);
#line 730 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_s390_pci_list_entry(uint32_t g_l2, uint32_t vid, uint32_t did, uint32_t fid, uint32_t fh)
{
    if (true) {
        _nocheck__trace_s390_pci_list_entry(g_l2, vid, did, fid, fh);
    }
}

#define TRACE_S390_PCI_LIST_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_S390_PCI_LIST) || \
    false)

static inline void _nocheck__trace_s390_pci_list(uint32_t rc)
{
    if (trace_event_get_state(TRACE_S390_PCI_LIST) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 34 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:s390_pci_list " "failed rc 0x%x" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , rc);
#line 757 "trace/trace-hw_s390x.h"
        } else {
#line 34 "../hw/s390x/trace-events"
            qemu_log("s390_pci_list " "failed rc 0x%x" "\n", rc);
#line 761 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_s390_pci_list(uint32_t rc)
{
    if (true) {
        _nocheck__trace_s390_pci_list(rc);
    }
}

#define TRACE_S390_PCI_UNKNOWN_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_S390_PCI_UNKNOWN) || \
    false)

static inline void _nocheck__trace_s390_pci_unknown(const char * msg, uint32_t cmd)
{
    if (trace_event_get_state(TRACE_S390_PCI_UNKNOWN) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 35 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:s390_pci_unknown " "%s unknown command 0x%x" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , msg, cmd);
#line 788 "trace/trace-hw_s390x.h"
        } else {
#line 35 "../hw/s390x/trace-events"
            qemu_log("s390_pci_unknown " "%s unknown command 0x%x" "\n", msg, cmd);
#line 792 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_s390_pci_unknown(const char * msg, uint32_t cmd)
{
    if (true) {
        _nocheck__trace_s390_pci_unknown(msg, cmd);
    }
}

#define TRACE_S390_PCI_BAR_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_S390_PCI_BAR) || \
    false)

static inline void _nocheck__trace_s390_pci_bar(uint32_t bar, uint32_t addr, uint64_t size, uint32_t barsize)
{
    if (trace_event_get_state(TRACE_S390_PCI_BAR) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 36 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:s390_pci_bar " "bar %d addr 0x%x size 0x%" PRIx64 "barsize 0x%x" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , bar, addr, size, barsize);
#line 819 "trace/trace-hw_s390x.h"
        } else {
#line 36 "../hw/s390x/trace-events"
            qemu_log("s390_pci_bar " "bar %d addr 0x%x size 0x%" PRIx64 "barsize 0x%x" "\n", bar, addr, size, barsize);
#line 823 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_s390_pci_bar(uint32_t bar, uint32_t addr, uint64_t size, uint32_t barsize)
{
    if (true) {
        _nocheck__trace_s390_pci_bar(bar, addr, size, barsize);
    }
}

#define TRACE_S390_PCI_NODEV_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_S390_PCI_NODEV) || \
    false)

static inline void _nocheck__trace_s390_pci_nodev(const char * cmd, uint32_t fh)
{
    if (trace_event_get_state(TRACE_S390_PCI_NODEV) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 37 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:s390_pci_nodev " "%s no pci dev fh 0x%x" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , cmd, fh);
#line 850 "trace/trace-hw_s390x.h"
        } else {
#line 37 "../hw/s390x/trace-events"
            qemu_log("s390_pci_nodev " "%s no pci dev fh 0x%x" "\n", cmd, fh);
#line 854 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_s390_pci_nodev(const char * cmd, uint32_t fh)
{
    if (true) {
        _nocheck__trace_s390_pci_nodev(cmd, fh);
    }
}

#define TRACE_S390_PCI_INVALID_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_S390_PCI_INVALID) || \
    false)

static inline void _nocheck__trace_s390_pci_invalid(const char * cmd, uint32_t fh)
{
    if (trace_event_get_state(TRACE_S390_PCI_INVALID) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 38 "../hw/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:s390_pci_invalid " "%s invalid space fh 0x%x" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , cmd, fh);
#line 881 "trace/trace-hw_s390x.h"
        } else {
#line 38 "../hw/s390x/trace-events"
            qemu_log("s390_pci_invalid " "%s invalid space fh 0x%x" "\n", cmd, fh);
#line 885 "trace/trace-hw_s390x.h"
        }
    }
}

static inline void trace_s390_pci_invalid(const char * cmd, uint32_t fh)
{
    if (true) {
        _nocheck__trace_s390_pci_invalid(cmd, fh);
    }
}
#endif /* TRACE_HW_S390X_GENERATED_TRACERS_H */
