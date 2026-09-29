#pragma once

#include <concepts>

namespace startrack::core::math {

template <typename T>
concept Arithmetic = requires(T a, T b) {
  { a + b } -> std::same_as<T>;
  { a - b } -> std::same_as<T>;
  { a * b } -> std::same_as<T>;
  { a / b } -> std::same_as<T>;
};

template <Arithmetic T>
constexpr T square(const T& x) {
  return x * x;
}

template <Arithmetic T>
constexpr T cube(const T& x) {
  return x * x * x;
}

}  // namespace startrack::core::math
