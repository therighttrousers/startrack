add_library(startrack_core src/orbit.cpp)

target_link_libraries(startrack_core PRIVATE
        compiler_settings
)

target_include_directories(startrack_core PUBLIC include)
