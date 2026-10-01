cmake_minimum_required(VERSION 3.25)

project(StarTrack CXX)

# Error if not building for 64-bit
if (NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "Only 64-bit builds are supported.")
endif ()

include(FetchContent)

FetchContent_Declare(
        qdpp
        GIT_REPOSITORY https://github.com/lhprojects/qdpp.git
        GIT_TAG d81aa16f77da41172ce1a22e9cbbfb71000428dd
)

FetchContent_MakeAvailable(qdpp)

add_library(qd INTERFACE)
target_include_directories(qd SYSTEM INTERFACE ${qdpp_SOURCE_DIR}/include)

add_library(compiler_settings INTERFACE)
target_compile_features(compiler_settings INTERFACE cxx_std_20)
# Note: -frounding-math, -fsignaling-nans and /fp:strict are required for the qd library to work correctly
target_compile_options(compiler_settings INTERFACE
        $<$<CXX_COMPILER_ID:Clang,GNU>:-Wall -Wextra -Wpedantic -frounding-math -fsignaling-nans>
        $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive- /fp:strict>
)

enable_testing()

add_subdirectory(core)
add_subdirectory(app)
add_subdirectory(tests)
