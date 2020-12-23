#pragma once

#include <nn/types.h>
#include <gfl/mem/memory_resource.h>

namespace gfl {

template <typename T, size_t U, const size_t M>
struct Allocator {
    gfl::mem::MemoryResource* m_resource;
    const char* m_ownerFilePath;
    int m_ownerLineNumber;
};

}  // namespace gfl