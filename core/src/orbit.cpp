#include "startrack/core/orbit.hpp"

#include <cmath>
#include <numbers>

#include "startrack/core/math.hpp"

namespace startrack::core {

using std::sqrt;
using std::numbers::pi;

using namespace math;

auto orbital_period(const double semi_major_axis, const double mu) -> double {
  return 2 * pi * sqrt(cube(semi_major_axis) / mu);
}

}  // namespace startrack::core
