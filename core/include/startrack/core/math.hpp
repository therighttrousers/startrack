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
constexpr auto square(const T& x) -> T {
  return x * x;
}

template <Arithmetic T>
constexpr auto cube(const T& x) -> T {
  return x * x * x;
}

}  // namespace startrack::core::math
