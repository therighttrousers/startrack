#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <catch2/reporters/catch_reporter_registrars.hpp>

#include "qd.hpp"
#include "startrack/core/constants.hpp"
#include "startrack/core/orbit.hpp"

using Catch::Matchers::WithinRel;

using startrack::core::orbital_period;
using startrack::core::constants::earth;

// Make sure the FPU is correctly configured before any QD-using tests
CATCH_REGISTER_LISTENER(QDSetupListener)

// NOLINTBEGIN(readability-magic-numbers)

TEST_CASE("qd_working") {
  // `(0.3 - 0.2) * 10.0 == 1.0` is mathematically true, but false in 64-bit FP arithmetic if (all):
  // 1. The FPU has been configured to use 64-bit precision (not 80-bit precision, which is incompatible with QD)
  // 2. The FPU correctly rounds arithmetic operations to 64 bits
  // 3. The compiler doesn't optimize operations away; e.g. `0.3 - 0.2` => `0.1` at compile time
  REQUIRE(!((0.3 - 0.2) * 10.0 == 1.0));

  // Same test, 106-bit double-doubles
  const auto dd_ten = dd_real(10);
  REQUIRE(to_double((dd_real(3) / dd_ten - dd_real(2) / dd_ten) * dd_ten) == 1.0);

  // Same test, 212-bit quad-doubles
  const auto qd_ten = qd_real(10);
  REQUIRE(to_double((qd_real(3) / qd_ten - qd_real(2) / qd_ten) * qd_ten) == 1.0);
}

TEST_CASE("orbital_period") {
  REQUIRE_THAT(orbital_period(550e3 + earth.radius, earth.mu), WithinRel(95.649880250 * 60, 1e-9));
}

// NOLINTEND(readability-magic-numbers)
