#pragma once

#include "gflib3/include/core/engine/memory_object.h"

namespace gfl::text {
    class MsgData : gfl::engine::Object<gfl::engine::IObject> {
    public:
        MsgData(const MsgData&) = delete;
        void operator= (const MsgData&) = delete;
    };
} // namespace gfl::text
