#include <iomanip>
#include <iostream>
#include <limits>

#include "startrack/core/constants.hpp"
#include "startrack/core/orbit.hpp"

using startrack::core::orbital_period;
using startrack::core::constants::earth;

auto main() -> int {
  std::cout << std::setprecision(std::numeric_limits<double>::max_digits10);

  const double semi_major_axis = 550e3 + earth.radius;  // 550 km altitude
  // NOLINTNEXTLINE(readability-magic-numbers)
  std::cout << "Orbital Period: " << orbital_period(semi_major_axis, earth.mu) / 60 << " min\n";
  return 0;
}
