/* This file is autogenerated by tracetool, do not edit. */

#ifndef TRACE_HW_SPARC64_GENERATED_TRACERS_H
#define TRACE_HW_SPARC64_GENERATED_TRACERS_H

#include "trace/control.h"

extern TraceEvent _TRACE_EBUS_ISA_IRQ_HANDLER_EVENT;
extern TraceEvent _TRACE_SUN4U_IOMMU_MEM_READ_EVENT;
extern TraceEvent _TRACE_SUN4U_IOMMU_MEM_WRITE_EVENT;
extern TraceEvent _TRACE_SUN4U_IOMMU_TRANSLATE_EVENT;
extern TraceEvent _TRACE_SPARC64_CPU_IVEC_RAISE_IRQ_EVENT;
extern TraceEvent _TRACE_SPARC64_CPU_IVEC_LOWER_IRQ_EVENT;
extern TraceEvent _TRACE_SPARC64_CPU_TICK_IRQ_DISABLED_EVENT;
extern TraceEvent _TRACE_SPARC64_CPU_TICK_IRQ_FIRE_EVENT;
extern TraceEvent _TRACE_SPARC64_CPU_STICK_IRQ_DISABLED_EVENT;
extern TraceEvent _TRACE_SPARC64_CPU_STICK_IRQ_FIRE_EVENT;
extern TraceEvent _TRACE_SPARC64_CPU_HSTICK_IRQ_DISABLED_EVENT;
extern TraceEvent _TRACE_SPARC64_CPU_HSTICK_IRQ_FIRE_EVENT;
extern TraceEvent _TRACE_SPARC64_CPU_TICK_SET_COUNT_EVENT;
extern TraceEvent _TRACE_SPARC64_CPU_TICK_GET_COUNT_EVENT;
extern TraceEvent _TRACE_SPARC64_CPU_TICK_SET_LIMIT_EVENT;
extern TraceEvent _TRACE_SPARC64_CPU_TICK_SET_LIMIT_ZERO_EVENT;
extern uint16_t _TRACE_EBUS_ISA_IRQ_HANDLER_DSTATE;
extern uint16_t _TRACE_SUN4U_IOMMU_MEM_READ_DSTATE;
extern uint16_t _TRACE_SUN4U_IOMMU_MEM_WRITE_DSTATE;
extern uint16_t _TRACE_SUN4U_IOMMU_TRANSLATE_DSTATE;
extern uint16_t _TRACE_SPARC64_CPU_IVEC_RAISE_IRQ_DSTATE;
extern uint16_t _TRACE_SPARC64_CPU_IVEC_LOWER_IRQ_DSTATE;
extern uint16_t _TRACE_SPARC64_CPU_TICK_IRQ_DISABLED_DSTATE;
extern uint16_t _TRACE_SPARC64_CPU_TICK_IRQ_FIRE_DSTATE;
extern uint16_t _TRACE_SPARC64_CPU_STICK_IRQ_DISABLED_DSTATE;
extern uint16_t _TRACE_SPARC64_CPU_STICK_IRQ_FIRE_DSTATE;
extern uint16_t _TRACE_SPARC64_CPU_HSTICK_IRQ_DISABLED_DSTATE;
extern uint16_t _TRACE_SPARC64_CPU_HSTICK_IRQ_FIRE_DSTATE;
extern uint16_t _TRACE_SPARC64_CPU_TICK_SET_COUNT_DSTATE;
extern uint16_t _TRACE_SPARC64_CPU_TICK_GET_COUNT_DSTATE;
extern uint16_t _TRACE_SPARC64_CPU_TICK_SET_LIMIT_DSTATE;
extern uint16_t _TRACE_SPARC64_CPU_TICK_SET_LIMIT_ZERO_DSTATE;
#define TRACE_EBUS_ISA_IRQ_HANDLER_ENABLED 1
#define TRACE_SUN4U_IOMMU_MEM_READ_ENABLED 1
#define TRACE_SUN4U_IOMMU_MEM_WRITE_ENABLED 1
#define TRACE_SUN4U_IOMMU_TRANSLATE_ENABLED 1
#define TRACE_SPARC64_CPU_IVEC_RAISE_IRQ_ENABLED 1
#define TRACE_SPARC64_CPU_IVEC_LOWER_IRQ_ENABLED 1
#define TRACE_SPARC64_CPU_TICK_IRQ_DISABLED_ENABLED 1
#define TRACE_SPARC64_CPU_TICK_IRQ_FIRE_ENABLED 1
#define TRACE_SPARC64_CPU_STICK_IRQ_DISABLED_ENABLED 1
#define TRACE_SPARC64_CPU_STICK_IRQ_FIRE_ENABLED 1
#define TRACE_SPARC64_CPU_HSTICK_IRQ_DISABLED_ENABLED 1
#define TRACE_SPARC64_CPU_HSTICK_IRQ_FIRE_ENABLED 1
#define TRACE_SPARC64_CPU_TICK_SET_COUNT_ENABLED 1
#define TRACE_SPARC64_CPU_TICK_GET_COUNT_ENABLED 1
#define TRACE_SPARC64_CPU_TICK_SET_LIMIT_ENABLED 1
#define TRACE_SPARC64_CPU_TICK_SET_LIMIT_ZERO_ENABLED 1
#include "qemu/log-for-trace.h"
#include "qemu/error-report.h"


#define TRACE_EBUS_ISA_IRQ_HANDLER_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_EBUS_ISA_IRQ_HANDLER) || \
    false)

static inline void _nocheck__trace_ebus_isa_irq_handler(int n, int level)
{
    if (trace_event_get_state(TRACE_EBUS_ISA_IRQ_HANDLER) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 4 "../hw/sparc64/trace-events"
            qemu_log("%d@%zu.%06zu:ebus_isa_irq_handler " "Set ISA IRQ %d level %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , n, level);
#line 76 "trace/trace-hw_sparc64.h"
        } else {
#line 4 "../hw/sparc64/trace-events"
            qemu_log("ebus_isa_irq_handler " "Set ISA IRQ %d level %d" "\n", n, level);
#line 80 "trace/trace-hw_sparc64.h"
        }
    }
}

static inline void trace_ebus_isa_irq_handler(int n, int level)
{
    if (true) {
        _nocheck__trace_ebus_isa_irq_handler(n, level);
    }
}

#define TRACE_SUN4U_IOMMU_MEM_READ_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_SUN4U_IOMMU_MEM_READ) || \
    false)

static inline void _nocheck__trace_sun4u_iommu_mem_read(uint64_t addr, uint64_t val, int size)
{
    if (trace_event_get_state(TRACE_SUN4U_IOMMU_MEM_READ) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 7 "../hw/sparc64/trace-events"
            qemu_log("%d@%zu.%06zu:sun4u_iommu_mem_read " "addr: 0x%"PRIx64" val: 0x%"PRIx64" size: %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , addr, val, size);
#line 107 "trace/trace-hw_sparc64.h"
        } else {
#line 7 "../hw/sparc64/trace-events"
            qemu_log("sun4u_iommu_mem_read " "addr: 0x%"PRIx64" val: 0x%"PRIx64" size: %d" "\n", addr, val, size);
#line 111 "trace/trace-hw_sparc64.h"
        }
    }
}

static inline void trace_sun4u_iommu_mem_read(uint64_t addr, uint64_t val, int size)
{
    if (true) {
        _nocheck__trace_sun4u_iommu_mem_read(addr, val, size);
    }
}

#define TRACE_SUN4U_IOMMU_MEM_WRITE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_SUN4U_IOMMU_MEM_WRITE) || \
    false)

static inline void _nocheck__trace_sun4u_iommu_mem_write(uint64_t addr, uint64_t val, int size)
{
    if (trace_event_get_state(TRACE_SUN4U_IOMMU_MEM_WRITE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 8 "../hw/sparc64/trace-events"
            qemu_log("%d@%zu.%06zu:sun4u_iommu_mem_write " "addr: 0x%"PRIx64" val: 0x%"PRIx64" size: %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , addr, val, size);
#line 138 "trace/trace-hw_sparc64.h"
        } else {
#line 8 "../hw/sparc64/trace-events"
            qemu_log("sun4u_iommu_mem_write " "addr: 0x%"PRIx64" val: 0x%"PRIx64" size: %d" "\n", addr, val, size);
#line 142 "trace/trace-hw_sparc64.h"
        }
    }
}

static inline void trace_sun4u_iommu_mem_write(uint64_t addr, uint64_t val, int size)
{
    if (true) {
        _nocheck__trace_sun4u_iommu_mem_write(addr, val, size);
    }
}

#define TRACE_SUN4U_IOMMU_TRANSLATE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_SUN4U_IOMMU_TRANSLATE) || \
    false)

static inline void _nocheck__trace_sun4u_iommu_translate(uint64_t addr, uint64_t trans_addr, uint64_t tte)
{
    if (trace_event_get_state(TRACE_SUN4U_IOMMU_TRANSLATE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 9 "../hw/sparc64/trace-events"
            qemu_log("%d@%zu.%06zu:sun4u_iommu_translate " "xlate 0x%"PRIx64" => pa 0x%"PRIx64" tte: 0x%"PRIx64 "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , addr, trans_addr, tte);
#line 169 "trace/trace-hw_sparc64.h"
        } else {
#line 9 "../hw/sparc64/trace-events"
            qemu_log("sun4u_iommu_translate " "xlate 0x%"PRIx64" => pa 0x%"PRIx64" tte: 0x%"PRIx64 "\n", addr, trans_addr, tte);
#line 173 "trace/trace-hw_sparc64.h"
        }
    }
}

static inline void trace_sun4u_iommu_translate(uint64_t addr, uint64_t trans_addr, uint64_t tte)
{
    if (true) {
        _nocheck__trace_sun4u_iommu_translate(addr, trans_addr, tte);
    }
}

#define TRACE_SPARC64_CPU_IVEC_RAISE_IRQ_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_SPARC64_CPU_IVEC_RAISE_IRQ) || \
    false)

static inline void _nocheck__trace_sparc64_cpu_ivec_raise_irq(int irq)
{
    if (trace_event_get_state(TRACE_SPARC64_CPU_IVEC_RAISE_IRQ) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 12 "../hw/sparc64/trace-events"
            qemu_log("%d@%zu.%06zu:sparc64_cpu_ivec_raise_irq " "Raise IVEC IRQ %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , irq);
#line 200 "trace/trace-hw_sparc64.h"
        } else {
#line 12 "../hw/sparc64/trace-events"
            qemu_log("sparc64_cpu_ivec_raise_irq " "Raise IVEC IRQ %d" "\n", irq);
#line 204 "trace/trace-hw_sparc64.h"
        }
    }
}

static inline void trace_sparc64_cpu_ivec_raise_irq(int irq)
{
    if (true) {
        _nocheck__trace_sparc64_cpu_ivec_raise_irq(irq);
    }
}

#define TRACE_SPARC64_CPU_IVEC_LOWER_IRQ_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_SPARC64_CPU_IVEC_LOWER_IRQ) || \
    false)

static inline void _nocheck__trace_sparc64_cpu_ivec_lower_irq(int irq)
{
    if (trace_event_get_state(TRACE_SPARC64_CPU_IVEC_LOWER_IRQ) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 13 "../hw/sparc64/trace-events"
            qemu_log("%d@%zu.%06zu:sparc64_cpu_ivec_lower_irq " "Lower IVEC IRQ %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , irq);
#line 231 "trace/trace-hw_sparc64.h"
        } else {
#line 13 "../hw/sparc64/trace-events"
            qemu_log("sparc64_cpu_ivec_lower_irq " "Lower IVEC IRQ %d" "\n", irq);
#line 235 "trace/trace-hw_sparc64.h"
        }
    }
}

static inline void trace_sparc64_cpu_ivec_lower_irq(int irq)
{
    if (true) {
        _nocheck__trace_sparc64_cpu_ivec_lower_irq(irq);
    }
}

#define TRACE_SPARC64_CPU_TICK_IRQ_DISABLED_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_SPARC64_CPU_TICK_IRQ_DISABLED) || \
    false)

static inline void _nocheck__trace_sparc64_cpu_tick_irq_disabled(void)
{
    if (trace_event_get_state(TRACE_SPARC64_CPU_TICK_IRQ_DISABLED) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 14 "../hw/sparc64/trace-events"
            qemu_log("%d@%zu.%06zu:sparc64_cpu_tick_irq_disabled " "tick_irq: softint disabled" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     );
#line 262 "trace/trace-hw_sparc64.h"
        } else {
#line 14 "../hw/sparc64/trace-events"
            qemu_log("sparc64_cpu_tick_irq_disabled " "tick_irq: softint disabled" "\n");
#line 266 "trace/trace-hw_sparc64.h"
        }
    }
}

static inline void trace_sparc64_cpu_tick_irq_disabled(void)
{
    if (true) {
        _nocheck__trace_sparc64_cpu_tick_irq_disabled();
    }
}

#define TRACE_SPARC64_CPU_TICK_IRQ_FIRE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_SPARC64_CPU_TICK_IRQ_FIRE) || \
    false)

static inline void _nocheck__trace_sparc64_cpu_tick_irq_fire(void)
{
    if (trace_event_get_state(TRACE_SPARC64_CPU_TICK_IRQ_FIRE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 15 "../hw/sparc64/trace-events"
            qemu_log("%d@%zu.%06zu:sparc64_cpu_tick_irq_fire " "tick_irq: fire" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     );
#line 293 "trace/trace-hw_sparc64.h"
        } else {
#line 15 "../hw/sparc64/trace-events"
            qemu_log("sparc64_cpu_tick_irq_fire " "tick_irq: fire" "\n");
#line 297 "trace/trace-hw_sparc64.h"
        }
    }
}

static inline void trace_sparc64_cpu_tick_irq_fire(void)
{
    if (true) {
        _nocheck__trace_sparc64_cpu_tick_irq_fire();
    }
}

#define TRACE_SPARC64_CPU_STICK_IRQ_DISABLED_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_SPARC64_CPU_STICK_IRQ_DISABLED) || \
    false)

static inline void _nocheck__trace_sparc64_cpu_stick_irq_disabled(void)
{
    if (trace_event_get_state(TRACE_SPARC64_CPU_STICK_IRQ_DISABLED) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 16 "../hw/sparc64/trace-events"
            qemu_log("%d@%zu.%06zu:sparc64_cpu_stick_irq_disabled " "stick_irq: softint disabled" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     );
#line 324 "trace/trace-hw_sparc64.h"
        } else {
#line 16 "../hw/sparc64/trace-events"
            qemu_log("sparc64_cpu_stick_irq_disabled " "stick_irq: softint disabled" "\n");
#line 328 "trace/trace-hw_sparc64.h"
        }
    }
}

static inline void trace_sparc64_cpu_stick_irq_disabled(void)
{
    if (true) {
        _nocheck__trace_sparc64_cpu_stick_irq_disabled();
    }
}

#define TRACE_SPARC64_CPU_STICK_IRQ_FIRE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_SPARC64_CPU_STICK_IRQ_FIRE) || \
    false)

static inline void _nocheck__trace_sparc64_cpu_stick_irq_fire(void)
{
    if (trace_event_get_state(TRACE_SPARC64_CPU_STICK_IRQ_FIRE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 17 "../hw/sparc64/trace-events"
            qemu_log("%d@%zu.%06zu:sparc64_cpu_stick_irq_fire " "stick_irq: fire" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     );
#line 355 "trace/trace-hw_sparc64.h"
        } else {
#line 17 "../hw/sparc64/trace-events"
            qemu_log("sparc64_cpu_stick_irq_fire " "stick_irq: fire" "\n");
#line 359 "trace/trace-hw_sparc64.h"
        }
    }
}

static inline void trace_sparc64_cpu_stick_irq_fire(void)
{
    if (true) {
        _nocheck__trace_sparc64_cpu_stick_irq_fire();
    }
}

#define TRACE_SPARC64_CPU_HSTICK_IRQ_DISABLED_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_SPARC64_CPU_HSTICK_IRQ_DISABLED) || \
    false)

static inline void _nocheck__trace_sparc64_cpu_hstick_irq_disabled(void)
{
    if (trace_event_get_state(TRACE_SPARC64_CPU_HSTICK_IRQ_DISABLED) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 18 "../hw/sparc64/trace-events"
            qemu_log("%d@%zu.%06zu:sparc64_cpu_hstick_irq_disabled " "hstick_irq: softint disabled" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     );
#line 386 "trace/trace-hw_sparc64.h"
        } else {
#line 18 "../hw/sparc64/trace-events"
            qemu_log("sparc64_cpu_hstick_irq_disabled " "hstick_irq: softint disabled" "\n");
#line 390 "trace/trace-hw_sparc64.h"
        }
    }
}

static inline void trace_sparc64_cpu_hstick_irq_disabled(void)
{
    if (true) {
        _nocheck__trace_sparc64_cpu_hstick_irq_disabled();
    }
}

#define TRACE_SPARC64_CPU_HSTICK_IRQ_FIRE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_SPARC64_CPU_HSTICK_IRQ_FIRE) || \
    false)

static inline void _nocheck__trace_sparc64_cpu_hstick_irq_fire(void)
{
    if (trace_event_get_state(TRACE_SPARC64_CPU_HSTICK_IRQ_FIRE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 19 "../hw/sparc64/trace-events"
            qemu_log("%d@%zu.%06zu:sparc64_cpu_hstick_irq_fire " "hstick_irq: fire" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     );
#line 417 "trace/trace-hw_sparc64.h"
        } else {
#line 19 "../hw/sparc64/trace-events"
            qemu_log("sparc64_cpu_hstick_irq_fire " "hstick_irq: fire" "\n");
#line 421 "trace/trace-hw_sparc64.h"
        }
    }
}

static inline void trace_sparc64_cpu_hstick_irq_fire(void)
{
    if (true) {
        _nocheck__trace_sparc64_cpu_hstick_irq_fire();
    }
}

#define TRACE_SPARC64_CPU_TICK_SET_COUNT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_SPARC64_CPU_TICK_SET_COUNT) || \
    false)

static inline void _nocheck__trace_sparc64_cpu_tick_set_count(const char * name, uint64_t real_count, const char * npt, void * p)
{
    if (trace_event_get_state(TRACE_SPARC64_CPU_TICK_SET_COUNT) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 20 "../hw/sparc64/trace-events"
            qemu_log("%d@%zu.%06zu:sparc64_cpu_tick_set_count " "%s set_count count=0x%"PRIx64" (npt %s) p=%p" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , name, real_count, npt, p);
#line 448 "trace/trace-hw_sparc64.h"
        } else {
#line 20 "../hw/sparc64/trace-events"
            qemu_log("sparc64_cpu_tick_set_count " "%s set_count count=0x%"PRIx64" (npt %s) p=%p" "\n", name, real_count, npt, p);
#line 452 "trace/trace-hw_sparc64.h"
        }
    }
}

static inline void trace_sparc64_cpu_tick_set_count(const char * name, uint64_t real_count, const char * npt, void * p)
{
    if (true) {
        _nocheck__trace_sparc64_cpu_tick_set_count(name, real_count, npt, p);
    }
}

#define TRACE_SPARC64_CPU_TICK_GET_COUNT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_SPARC64_CPU_TICK_GET_COUNT) || \
    false)

static inline void _nocheck__trace_sparc64_cpu_tick_get_count(const char * name, uint64_t real_count, const char * npt, void * p)
{
    if (trace_event_get_state(TRACE_SPARC64_CPU_TICK_GET_COUNT) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 21 "../hw/sparc64/trace-events"
            qemu_log("%d@%zu.%06zu:sparc64_cpu_tick_get_count " "%s get_count count=0x%"PRIx64" (npt %s) p=%p" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , name, real_count, npt, p);
#line 479 "trace/trace-hw_sparc64.h"
        } else {
#line 21 "../hw/sparc64/trace-events"
            qemu_log("sparc64_cpu_tick_get_count " "%s get_count count=0x%"PRIx64" (npt %s) p=%p" "\n", name, real_count, npt, p);
#line 483 "trace/trace-hw_sparc64.h"
        }
    }
}

static inline void trace_sparc64_cpu_tick_get_count(const char * name, uint64_t real_count, const char * npt, void * p)
{
    if (true) {
        _nocheck__trace_sparc64_cpu_tick_get_count(name, real_count, npt, p);
    }
}

#define TRACE_SPARC64_CPU_TICK_SET_LIMIT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_SPARC64_CPU_TICK_SET_LIMIT) || \
    false)

static inline void _nocheck__trace_sparc64_cpu_tick_set_limit(const char * name, uint64_t real_limit, const char * dis, void * p, uint64_t limit, uint64_t t, uint64_t dt)
{
    if (trace_event_get_state(TRACE_SPARC64_CPU_TICK_SET_LIMIT) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 22 "../hw/sparc64/trace-events"
            qemu_log("%d@%zu.%06zu:sparc64_cpu_tick_set_limit " "%s set_limit limit=0x%"PRIx64 " (%s) p=%p called with limit=0x%"PRIx64" at 0x%"PRIx64" (delta=0x%"PRIx64")" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , name, real_limit, dis, p, limit, t, dt);
#line 510 "trace/trace-hw_sparc64.h"
        } else {
#line 22 "../hw/sparc64/trace-events"
            qemu_log("sparc64_cpu_tick_set_limit " "%s set_limit limit=0x%"PRIx64 " (%s) p=%p called with limit=0x%"PRIx64" at 0x%"PRIx64" (delta=0x%"PRIx64")" "\n", name, real_limit, dis, p, limit, t, dt);
#line 514 "trace/trace-hw_sparc64.h"
        }
    }
}

static inline void trace_sparc64_cpu_tick_set_limit(const char * name, uint64_t real_limit, const char * dis, void * p, uint64_t limit, uint64_t t, uint64_t dt)
{
    if (true) {
        _nocheck__trace_sparc64_cpu_tick_set_limit(name, real_limit, dis, p, limit, t, dt);
    }
}

#define TRACE_SPARC64_CPU_TICK_SET_LIMIT_ZERO_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_SPARC64_CPU_TICK_SET_LIMIT_ZERO) || \
    false)

static inline void _nocheck__trace_sparc64_cpu_tick_set_limit_zero(const char * name)
{
    if (trace_event_get_state(TRACE_SPARC64_CPU_TICK_SET_LIMIT_ZERO) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 23 "../hw/sparc64/trace-events"
            qemu_log("%d@%zu.%06zu:sparc64_cpu_tick_set_limit_zero " "%s set_limit limit=ZERO - not starting timer" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , name);
#line 541 "trace/trace-hw_sparc64.h"
        } else {
#line 23 "../hw/sparc64/trace-events"
            qemu_log("sparc64_cpu_tick_set_limit_zero " "%s set_limit limit=ZERO - not starting timer" "\n", name);
#line 545 "trace/trace-hw_sparc64.h"
        }
    }
}

static inline void trace_sparc64_cpu_tick_set_limit_zero(const char * name)
{
    if (true) {
        _nocheck__trace_sparc64_cpu_tick_set_limit_zero(name);
    }
}
#endif /* TRACE_HW_SPARC64_GENERATED_TRACERS_H */
