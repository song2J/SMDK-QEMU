/* This file is autogenerated by tracetool, do not edit. */

#ifndef TRACE_QAPI_COMMANDS_CXL_TRACE_EVENTS_GENERATED_TRACERS_H
#define TRACE_QAPI_COMMANDS_CXL_TRACE_EVENTS_GENERATED_TRACERS_H

#include "trace/control.h"

extern TraceEvent _TRACE_QMP_ENTER_CXL_INJECT_GENERAL_MEDIA_EVENT_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_CXL_INJECT_GENERAL_MEDIA_EVENT_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_CXL_INJECT_DRAM_EVENT_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_CXL_INJECT_DRAM_EVENT_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_CXL_INJECT_MEMORY_MODULE_EVENT_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_CXL_INJECT_MEMORY_MODULE_EVENT_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_CXL_INJECT_POISON_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_CXL_INJECT_POISON_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_CXL_INJECT_UNCORRECTABLE_ERRORS_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_CXL_INJECT_UNCORRECTABLE_ERRORS_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_CXL_INJECT_CORRECTABLE_ERROR_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_CXL_INJECT_CORRECTABLE_ERROR_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_CXL_ADD_DYNAMIC_CAPACITY_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_CXL_ADD_DYNAMIC_CAPACITY_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_CXL_RELEASE_DYNAMIC_CAPACITY_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_CXL_RELEASE_DYNAMIC_CAPACITY_EVENT;
extern uint16_t _TRACE_QMP_ENTER_CXL_INJECT_GENERAL_MEDIA_EVENT_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_CXL_INJECT_GENERAL_MEDIA_EVENT_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_CXL_INJECT_DRAM_EVENT_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_CXL_INJECT_DRAM_EVENT_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_CXL_INJECT_MEMORY_MODULE_EVENT_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_CXL_INJECT_MEMORY_MODULE_EVENT_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_CXL_INJECT_POISON_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_CXL_INJECT_POISON_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_CXL_INJECT_UNCORRECTABLE_ERRORS_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_CXL_INJECT_UNCORRECTABLE_ERRORS_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_CXL_INJECT_CORRECTABLE_ERROR_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_CXL_INJECT_CORRECTABLE_ERROR_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_CXL_ADD_DYNAMIC_CAPACITY_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_CXL_ADD_DYNAMIC_CAPACITY_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_CXL_RELEASE_DYNAMIC_CAPACITY_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_CXL_RELEASE_DYNAMIC_CAPACITY_DSTATE;
#define TRACE_QMP_ENTER_CXL_INJECT_GENERAL_MEDIA_EVENT_ENABLED 1
#define TRACE_QMP_EXIT_CXL_INJECT_GENERAL_MEDIA_EVENT_ENABLED 1
#define TRACE_QMP_ENTER_CXL_INJECT_DRAM_EVENT_ENABLED 1
#define TRACE_QMP_EXIT_CXL_INJECT_DRAM_EVENT_ENABLED 1
#define TRACE_QMP_ENTER_CXL_INJECT_MEMORY_MODULE_EVENT_ENABLED 1
#define TRACE_QMP_EXIT_CXL_INJECT_MEMORY_MODULE_EVENT_ENABLED 1
#define TRACE_QMP_ENTER_CXL_INJECT_POISON_ENABLED 1
#define TRACE_QMP_EXIT_CXL_INJECT_POISON_ENABLED 1
#define TRACE_QMP_ENTER_CXL_INJECT_UNCORRECTABLE_ERRORS_ENABLED 1
#define TRACE_QMP_EXIT_CXL_INJECT_UNCORRECTABLE_ERRORS_ENABLED 1
#define TRACE_QMP_ENTER_CXL_INJECT_CORRECTABLE_ERROR_ENABLED 1
#define TRACE_QMP_EXIT_CXL_INJECT_CORRECTABLE_ERROR_ENABLED 1
#define TRACE_QMP_ENTER_CXL_ADD_DYNAMIC_CAPACITY_ENABLED 1
#define TRACE_QMP_EXIT_CXL_ADD_DYNAMIC_CAPACITY_ENABLED 1
#define TRACE_QMP_ENTER_CXL_RELEASE_DYNAMIC_CAPACITY_ENABLED 1
#define TRACE_QMP_EXIT_CXL_RELEASE_DYNAMIC_CAPACITY_ENABLED 1
#include "qemu/log-for-trace.h"
#include "qemu/error-report.h"


#define TRACE_QMP_ENTER_CXL_INJECT_GENERAL_MEDIA_EVENT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_CXL_INJECT_GENERAL_MEDIA_EVENT) || \
    false)

static inline void _nocheck__trace_qmp_enter_cxl_inject_general_media_event(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_CXL_INJECT_GENERAL_MEDIA_EVENT) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 3 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_cxl_inject_general_media_event " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 76 "trace/trace-qapi_commands_cxl_trace_events.h"
        } else {
#line 3 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("qmp_enter_cxl_inject_general_media_event " "%s" "\n", json);
#line 80 "trace/trace-qapi_commands_cxl_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_cxl_inject_general_media_event(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_cxl_inject_general_media_event(json);
    }
}

#define TRACE_QMP_EXIT_CXL_INJECT_GENERAL_MEDIA_EVENT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_CXL_INJECT_GENERAL_MEDIA_EVENT) || \
    false)

static inline void _nocheck__trace_qmp_exit_cxl_inject_general_media_event(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_CXL_INJECT_GENERAL_MEDIA_EVENT) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 4 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_cxl_inject_general_media_event " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 107 "trace/trace-qapi_commands_cxl_trace_events.h"
        } else {
#line 4 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("qmp_exit_cxl_inject_general_media_event " "%s %d" "\n", result, succeeded);
#line 111 "trace/trace-qapi_commands_cxl_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_cxl_inject_general_media_event(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_cxl_inject_general_media_event(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_CXL_INJECT_DRAM_EVENT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_CXL_INJECT_DRAM_EVENT) || \
    false)

static inline void _nocheck__trace_qmp_enter_cxl_inject_dram_event(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_CXL_INJECT_DRAM_EVENT) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 5 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_cxl_inject_dram_event " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 138 "trace/trace-qapi_commands_cxl_trace_events.h"
        } else {
#line 5 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("qmp_enter_cxl_inject_dram_event " "%s" "\n", json);
#line 142 "trace/trace-qapi_commands_cxl_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_cxl_inject_dram_event(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_cxl_inject_dram_event(json);
    }
}

#define TRACE_QMP_EXIT_CXL_INJECT_DRAM_EVENT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_CXL_INJECT_DRAM_EVENT) || \
    false)

static inline void _nocheck__trace_qmp_exit_cxl_inject_dram_event(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_CXL_INJECT_DRAM_EVENT) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 6 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_cxl_inject_dram_event " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 169 "trace/trace-qapi_commands_cxl_trace_events.h"
        } else {
#line 6 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("qmp_exit_cxl_inject_dram_event " "%s %d" "\n", result, succeeded);
#line 173 "trace/trace-qapi_commands_cxl_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_cxl_inject_dram_event(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_cxl_inject_dram_event(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_CXL_INJECT_MEMORY_MODULE_EVENT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_CXL_INJECT_MEMORY_MODULE_EVENT) || \
    false)

static inline void _nocheck__trace_qmp_enter_cxl_inject_memory_module_event(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_CXL_INJECT_MEMORY_MODULE_EVENT) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 7 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_cxl_inject_memory_module_event " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 200 "trace/trace-qapi_commands_cxl_trace_events.h"
        } else {
#line 7 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("qmp_enter_cxl_inject_memory_module_event " "%s" "\n", json);
#line 204 "trace/trace-qapi_commands_cxl_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_cxl_inject_memory_module_event(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_cxl_inject_memory_module_event(json);
    }
}

#define TRACE_QMP_EXIT_CXL_INJECT_MEMORY_MODULE_EVENT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_CXL_INJECT_MEMORY_MODULE_EVENT) || \
    false)

static inline void _nocheck__trace_qmp_exit_cxl_inject_memory_module_event(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_CXL_INJECT_MEMORY_MODULE_EVENT) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 8 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_cxl_inject_memory_module_event " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 231 "trace/trace-qapi_commands_cxl_trace_events.h"
        } else {
#line 8 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("qmp_exit_cxl_inject_memory_module_event " "%s %d" "\n", result, succeeded);
#line 235 "trace/trace-qapi_commands_cxl_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_cxl_inject_memory_module_event(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_cxl_inject_memory_module_event(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_CXL_INJECT_POISON_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_CXL_INJECT_POISON) || \
    false)

static inline void _nocheck__trace_qmp_enter_cxl_inject_poison(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_CXL_INJECT_POISON) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 9 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_cxl_inject_poison " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 262 "trace/trace-qapi_commands_cxl_trace_events.h"
        } else {
#line 9 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("qmp_enter_cxl_inject_poison " "%s" "\n", json);
#line 266 "trace/trace-qapi_commands_cxl_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_cxl_inject_poison(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_cxl_inject_poison(json);
    }
}

#define TRACE_QMP_EXIT_CXL_INJECT_POISON_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_CXL_INJECT_POISON) || \
    false)

static inline void _nocheck__trace_qmp_exit_cxl_inject_poison(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_CXL_INJECT_POISON) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 10 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_cxl_inject_poison " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 293 "trace/trace-qapi_commands_cxl_trace_events.h"
        } else {
#line 10 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("qmp_exit_cxl_inject_poison " "%s %d" "\n", result, succeeded);
#line 297 "trace/trace-qapi_commands_cxl_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_cxl_inject_poison(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_cxl_inject_poison(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_CXL_INJECT_UNCORRECTABLE_ERRORS_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_CXL_INJECT_UNCORRECTABLE_ERRORS) || \
    false)

static inline void _nocheck__trace_qmp_enter_cxl_inject_uncorrectable_errors(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_CXL_INJECT_UNCORRECTABLE_ERRORS) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 11 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_cxl_inject_uncorrectable_errors " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 324 "trace/trace-qapi_commands_cxl_trace_events.h"
        } else {
#line 11 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("qmp_enter_cxl_inject_uncorrectable_errors " "%s" "\n", json);
#line 328 "trace/trace-qapi_commands_cxl_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_cxl_inject_uncorrectable_errors(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_cxl_inject_uncorrectable_errors(json);
    }
}

#define TRACE_QMP_EXIT_CXL_INJECT_UNCORRECTABLE_ERRORS_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_CXL_INJECT_UNCORRECTABLE_ERRORS) || \
    false)

static inline void _nocheck__trace_qmp_exit_cxl_inject_uncorrectable_errors(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_CXL_INJECT_UNCORRECTABLE_ERRORS) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 12 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_cxl_inject_uncorrectable_errors " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 355 "trace/trace-qapi_commands_cxl_trace_events.h"
        } else {
#line 12 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("qmp_exit_cxl_inject_uncorrectable_errors " "%s %d" "\n", result, succeeded);
#line 359 "trace/trace-qapi_commands_cxl_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_cxl_inject_uncorrectable_errors(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_cxl_inject_uncorrectable_errors(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_CXL_INJECT_CORRECTABLE_ERROR_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_CXL_INJECT_CORRECTABLE_ERROR) || \
    false)

static inline void _nocheck__trace_qmp_enter_cxl_inject_correctable_error(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_CXL_INJECT_CORRECTABLE_ERROR) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 13 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_cxl_inject_correctable_error " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 386 "trace/trace-qapi_commands_cxl_trace_events.h"
        } else {
#line 13 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("qmp_enter_cxl_inject_correctable_error " "%s" "\n", json);
#line 390 "trace/trace-qapi_commands_cxl_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_cxl_inject_correctable_error(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_cxl_inject_correctable_error(json);
    }
}

#define TRACE_QMP_EXIT_CXL_INJECT_CORRECTABLE_ERROR_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_CXL_INJECT_CORRECTABLE_ERROR) || \
    false)

static inline void _nocheck__trace_qmp_exit_cxl_inject_correctable_error(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_CXL_INJECT_CORRECTABLE_ERROR) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 14 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_cxl_inject_correctable_error " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 417 "trace/trace-qapi_commands_cxl_trace_events.h"
        } else {
#line 14 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("qmp_exit_cxl_inject_correctable_error " "%s %d" "\n", result, succeeded);
#line 421 "trace/trace-qapi_commands_cxl_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_cxl_inject_correctable_error(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_cxl_inject_correctable_error(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_CXL_ADD_DYNAMIC_CAPACITY_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_CXL_ADD_DYNAMIC_CAPACITY) || \
    false)

static inline void _nocheck__trace_qmp_enter_cxl_add_dynamic_capacity(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_CXL_ADD_DYNAMIC_CAPACITY) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 15 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_cxl_add_dynamic_capacity " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 448 "trace/trace-qapi_commands_cxl_trace_events.h"
        } else {
#line 15 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("qmp_enter_cxl_add_dynamic_capacity " "%s" "\n", json);
#line 452 "trace/trace-qapi_commands_cxl_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_cxl_add_dynamic_capacity(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_cxl_add_dynamic_capacity(json);
    }
}

#define TRACE_QMP_EXIT_CXL_ADD_DYNAMIC_CAPACITY_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_CXL_ADD_DYNAMIC_CAPACITY) || \
    false)

static inline void _nocheck__trace_qmp_exit_cxl_add_dynamic_capacity(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_CXL_ADD_DYNAMIC_CAPACITY) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 16 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_cxl_add_dynamic_capacity " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 479 "trace/trace-qapi_commands_cxl_trace_events.h"
        } else {
#line 16 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("qmp_exit_cxl_add_dynamic_capacity " "%s %d" "\n", result, succeeded);
#line 483 "trace/trace-qapi_commands_cxl_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_cxl_add_dynamic_capacity(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_cxl_add_dynamic_capacity(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_CXL_RELEASE_DYNAMIC_CAPACITY_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_CXL_RELEASE_DYNAMIC_CAPACITY) || \
    false)

static inline void _nocheck__trace_qmp_enter_cxl_release_dynamic_capacity(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_CXL_RELEASE_DYNAMIC_CAPACITY) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 17 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_cxl_release_dynamic_capacity " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 510 "trace/trace-qapi_commands_cxl_trace_events.h"
        } else {
#line 17 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("qmp_enter_cxl_release_dynamic_capacity " "%s" "\n", json);
#line 514 "trace/trace-qapi_commands_cxl_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_cxl_release_dynamic_capacity(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_cxl_release_dynamic_capacity(json);
    }
}

#define TRACE_QMP_EXIT_CXL_RELEASE_DYNAMIC_CAPACITY_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_CXL_RELEASE_DYNAMIC_CAPACITY) || \
    false)

static inline void _nocheck__trace_qmp_exit_cxl_release_dynamic_capacity(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_CXL_RELEASE_DYNAMIC_CAPACITY) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 18 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_cxl_release_dynamic_capacity " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 541 "trace/trace-qapi_commands_cxl_trace_events.h"
        } else {
#line 18 "qapi/qapi-commands-cxl.trace-events"
            qemu_log("qmp_exit_cxl_release_dynamic_capacity " "%s %d" "\n", result, succeeded);
#line 545 "trace/trace-qapi_commands_cxl_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_cxl_release_dynamic_capacity(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_cxl_release_dynamic_capacity(result, succeeded);
    }
}
#endif /* TRACE_QAPI_COMMANDS_CXL_TRACE_EVENTS_GENERATED_TRACERS_H */
