project(gflib3 CXX ASM)

add_library(gflib3 OBJECT

  include/container/dynamic_array.h
  include/core/allocator.h
  include/core/engine/count_object.h
  include/core/engine/memory_object.h
  include/core/engine/object_handle.h
  include/core/mt/sync_object.h
  include/mem/manager.h

  include/mem/memory_resource.h
  src/mem/memory_resource.cpp

  include/core/singleton.h
  src/core/singleton.cpp

  include/text/msgdata.h
  src/text/msgdata.cpp)

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