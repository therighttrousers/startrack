#pragma once

namespace startrack::core::constants {

/** Gravitational constant */
inline constexpr double G = 6.67430e-11;  // m^3 kg^-1 s^-2

const struct PrimaryBody {
  /** Mass, in kg. */
  double mass;
  /** Equatorial radius, in m. */
  double radius;
  /** Gravitational parameter, in m^3 s^-2. Approx `G * this->mass` but more precise. */
  double mu;
};

inline constexpr PrimaryBody earth = {
    .mass = 5.9722e24,
    .radius = 6378.137e3,
    .mu = 3.986004418e14,
};

}  // namespace startrack::core::constants
