#pragma once

namespace startrack::core {

/**
 * Calculates the orbital period of a satellite using Kepler's third law.
 *
 * @param semi_major_axis The semi-major axis of the orbit, in meters.
 * @param mu The standard gravitational parameter of the primary body, in m^3/s^2.
 * @return The orbital period, in seconds.
 */
double   orbital_period(double semi_major_axis, double mu);

}  // namespace startrack::core
