#pragma once

#include <vector>
#include <nn/types.h>
#include <gfl/core/allocator.h>

namespace gfl::container {

// TODO: fix template
template <class T, size_t U> // -> 
class DynamicArray : Allocator<T, U>, std::vector<Allocator<T, U>> {

};

}  // namespace gfl::container