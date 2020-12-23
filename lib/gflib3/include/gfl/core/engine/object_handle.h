#pragma once

#include <boost/smart_ptr/intrusive_ptr.hpp>
#include <gfl/core/engine/count_object.h>

namespace gfl {

template <class T>
using IntrusivePtr = boost::intrusive_ptr<T>;

}

namespace gfl::engine {

template <class T>
struct ObjectHandle {
    gfl::IntrusivePtr<impl::CountObject> m_referenceCount;
};

}  // namespace gfl::engine
