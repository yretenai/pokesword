project(gflib3 CXX ASM)

add_library(gflib3 OBJECT
        include/gfl/macros.h

        include/gfl/container/dynamic_array.h
        include/gfl/core/allocator.h
        include/gfl/core/engine/count_object.h
        include/gfl/core/engine/memory_object.h
        include/gfl/core/engine/object_handle.h
        include/gfl/core/mt/sync_object.h
        include/gfl/mem/manager.h

        include/gfl/mem/memory_resource.h
        src/mem/memory_resource.cpp

        include/gfl/core/singleton.h
        src/core/singleton.cpp

        include/gfl/mem/mem.h
        src/mem/mem.cpp
        include/gfl/mem/internal.h

        include/gfl/text/msgdata.h
        src/text/msgdata.cpp include/gfl/mem/mutex.hpp)

if(MSVC)
  target_compile_options(gflib3 PRIVATE -Wall)
else()
  target_compile_options(gflib3 PRIVATE -Wall -Wextra)
  target_compile_options(gflib3 PRIVATE -Wno-invalid-offsetof)
  target_compile_options(gflib3 PRIVATE -fno-exceptions)
  target_compile_options(gflib3 PRIVATE -fno-strict-aliasing)
endif()

target_include_directories(gflib3 PUBLIC include/)

if(NOT TARGET NintendoSDK)
  add_subdirectory(../NintendoSDK)
endif()
target_link_libraries(gflib3 PUBLIC NintendoSDK)