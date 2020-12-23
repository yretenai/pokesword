#pragma once

#include <nn/types.h>

#include <gfl/macros.h>

namespace gfl::mem {
    inline constexpr u64 HAMMING_M1 = 0x5555555555555555;
    inline constexpr u64 HAMMING_M2 = 0x3333333333333333;
    inline constexpr u64 HAMMING_M4 = 0x0f0f0f0f0f0f0f0f;
    inline constexpr u64 HAMMING_M8 = 0x00ff00ff00ff00ff;
    inline constexpr u64 HAMMING_M16 = 0x0000ffff0000ffff;
    inline constexpr u64 HAMMING_M32 = 0x00000000ffffffff;
    inline constexpr u64 HAMMING_A = 0x0707070707070707;
    inline constexpr u64 HAMMING_B = 0x000f000f000f000f;
    inline constexpr u64 HAMMING_C = 0x0000001f0000001f;
    inline constexpr u64 HAMMING_H = 0x0101010101010101;

    // popcount64b.
    s64 GetBitCount(u64 value);

    // Gets Least Significant Bits, basically flips it I guess.
    u64 GetLSB(u64 value);

    // Gets Most Significant BIts
    u64 GetMSB(u64 value);

    // Gets the default memory resource controller
    // GetDefaultResource

    bool IsEnableGlobalAllocationLogging();
}

