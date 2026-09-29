cmake_minimum_required(VERSION 3.23)

project(StarTrack CXX)

# Error if not building for 64-bit
if (NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "Only 64-bit builds are supported.")
endif ()

add_library(compiler_settings INTERFACE)
target_compile_features(compiler_settings INTERFACE cxx_std_20)
target_compile_options(compiler_settings INTERFACE
        $<$<CXX_COMPILER_ID:Clang,GNU>:-Wall -Wextra>
        $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
)

enable_testing()

add_subdirectory(core)
add_subdirectory(app)
add_subdirectory(tests)
