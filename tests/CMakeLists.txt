add_executable(startrack_tests orbit_tests.cpp)

find_package(Catch2 3 CONFIG REQUIRED)

include(Catch)
catch_discover_tests(startrack_tests)

target_link_libraries(startrack_tests PRIVATE
        compiler_settings
        qd
        startrack_core
        Catch2::Catch2WithMain
)
