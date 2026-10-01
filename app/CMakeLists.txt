add_executable(startrack_app main.cpp)

target_link_libraries(startrack_app PRIVATE
        compiler_settings
        qd
        startrack_core
)
