#pragma once

#include <nn/types.h>
#include <nn/os.h>

#include <gfl/mem/mutex.hpp>
#include <gfl/macros.h>

namespace gfl::mem::impl {
    namespace DefaultResourceLock {
        extern gfl::mem::Mutex g_default_resource_lock;
    }

    // extern GlobalHeapResourceImpl g_debug_heap_resource;
    // extern GlobalHeapResourceImpl g_global_heap_resource;
    // extern GlobalInfoContainerImpl g_debug_info_container;
    extern int g_default_new_replaced_thread_id;
    // extern MemoryResource g_default_resource;
    // extern MemoryResource g_replaced_default_resource;

    // if set, wipe TLSF block memory, also the only var that uses camel case lol.
    extern bool g_dirtyMemoryOnAllocate GUARDED_BY(DefaultResourceLock::g_default_resource_lock);
    extern bool g_is_enable_logging GUARDED_BY(DefaultResourceLock::g_default_resource_lock);
    extern bool g_is_only_same_thread GUARDED_BY(DefaultResourceLock::g_default_resource_lock);
    extern bool g_assertion_for_implicit_allocation GUARDED_BY(DefaultResourceLock::g_default_resource_lock);
}