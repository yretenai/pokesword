#include <gfl/mem/mem.h>
#include <gfl/mem/internal.h>

namespace gfl::mem {
    namespace impl::DefaultResourceLock {
        gfl::mem::Mutex GUARDED_VAR(g_default_resource_lock);
    }

    using gfl::mem::impl::DefaultResourceLock::g_default_resource_lock;

    u64 GetLSB(u64 value) {
        if (value != 0) {
            u64 a = value | value << 1;
            a = a | a << 2;
            a = a | a << 4;
            a = a | a << 8;
            a = a | a << 0x10;
            a = a | a << 0x20;
            a = (a >> 1 & HAMMING_M1) + (a & HAMMING_M1);
            a = (a >> 2 & HAMMING_M2) + (a & HAMMING_M2);
            a = (a >> 4 & HAMMING_A) + (a & HAMMING_A);
            a = (a >> 8 & HAMMING_B) + (a & HAMMING_B);
            u64 b = (a >> 0x10 & HAMMING_C) + (a & HAMMING_C);
            return 0x40 - ((b >> 0x20) + b);
        }
        return 0xff;
    }

    u64 GetMSB(u64 value) {
        if (value != 0) {
            u64 a = value | value >> 1;
            a = a | a >> 2;
            a = a | a >> 4;
            a = a | a >> 8;
            a = a | a >> 0x10;
            u64 b = ((a >> 1) & HAMMING_M1) + (a & HAMMING_M1);
            b = (b >> 2 & HAMMING_M2) + (b & HAMMING_M2);
            b = (b >> 4 & HAMMING_A) + (b & HAMMING_A);
            u64 c = (b >> 8 & HAMMING_B) + (b & HAMMING_B);
            return (c >> 0x10) + (c & 0x1f) + 0xff;
        }

        return 0xff;
    }

    bool IsEnableGlobalAllocationLogging() EXCLUSIVE_LOCKS_REQUIRED(g_default_resource_lock) {
        return impl::g_is_enable_logging;
    }
}