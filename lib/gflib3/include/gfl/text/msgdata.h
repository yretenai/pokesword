#pragma once

#include <gfl/macros.h>
#include <gfl/core/engine/memory_object.h>

namespace gfl::text {
    class MsgData : gfl::engine::Object<gfl::engine::IObject> {
        GFL_DELETE_COPY_CONSTRUCTOR(MsgData);
    };
} // namespace gfl::text
