add_subdirectory(contents)

target_sources(pokesword PRIVATE
  main.cpp
)

if(NOT TARGET NintendoSDK)
    add_subdirectory(../lib/NintendoSDK)
endif()
target_link_libraries(pokesword PUBLIC NintendoSDK)

if(NOT TARGET gflib3)
    add_subdirectory(../lib/gflib3)
endif()
target_link_libraries(pokesword PUBLIC gflib3)
