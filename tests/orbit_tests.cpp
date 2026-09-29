#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include "startrack/core/constants.hpp"
#include "startrack/core/orbit.hpp"

using Catch::Matchers::WithinRel;

using startrack::core::orbital_period;
using startrack::core::constants::earth;

TEST_CASE("orbital_period") {
  REQUIRE_THAT(orbital_period(550e3 + earth.radius, earth.mu), WithinRel(95.649880250 * 60, 1e-9));
}
