#pragma once

#include <type_traits>
#include <concepts>
#include <cmath>
#include <complex>

#include "set.hpp"

namespace abstract_algebra {

struct natural_number {} N; constexpr bool is_set(natural_number) { return true; }
struct integer_number {} Z; constexpr bool is_set(integer_number) { return true; }
struct rational_number {} Q; constexpr bool is_set(rational_number) { return true; }
struct real_number {} R; constexpr bool is_set(real_number) { return true; }
struct complex_number {} C; constexpr bool is_set(complex_number) { return true; }

constexpr bool is_subset(natural_number N, integer_number Z) {
    return true;
}
constexpr bool is_subset(integer_number Z, rational_number Q) {
    return true;
}
constexpr bool is_subset(rational_number Q, real_number R) {
    return true;
}
constexpr bool is_subset(real_number R, complex_number C) {
    return true;
}

constexpr bool belong_to(std::integral auto i, natural_number N) {
    return i >= 0;
}
constexpr bool belong_to(std::floating_point auto f, natural_number N) {
    auto integer_part = f;
    return !std::isinf(f) && f >= 0 && 0 == std::modf(f, &integer_part);
}
template<typename T>
constexpr bool belong_to(std::complex<T> c, natural_number N) {
    return std::imag(c) == 0 && belong_to(std::real(c), N);
}

constexpr bool belong_to(std::integral auto i, integer_number Z) {
    return true;
}
constexpr bool belong_to(std::floating_point auto f, integer_number Z) {
    auto integer_part = f;
    return !std::isinf(f) && 0 == std::modf(f, &integer_part);
}
template<typename T>
constexpr bool belong_to(std::complex<T> c, integer_number Z) {
    return std::imag(c) == 0 && belong_to(std::real(c), N);
}

constexpr bool belong_to(std::integral auto i, rational_number Q) {
    return true;
}
constexpr bool belong_to(std::floating_point auto f, rational_number Q) {
    auto fp_class = std::fpclassify(f);
    return fp_class == FP_NORMAL ||
        fp_class == FP_SUBNORMAL ||
        fp_class == FP_ZERO;
}
template<typename T>
constexpr bool belong_to(std::complex<T> c, rational_number Q) {
    return std::imag(c) == 0 && belong_to(std::real(c), Q);
}

constexpr bool belong_to(std::integral auto i, real_number R) {
    return true;
}
constexpr bool belong_to(std::floating_point auto f, real_number R) {
    return belong_to(f, Q);
}
template<typename T>
constexpr bool belong_to(std::complex<T> c, real_number R) {
    return std::imag(c) == 0 && belong_to(std::real(c), R);
}

constexpr bool belong_to(std::integral auto i, complex_number C) {
    return true;
}
constexpr bool belong_to(std::floating_point auto f, complex_number C) {
    return belong_to(f, R);
}
template<typename T>
constexpr bool belong_to(std::complex<T> c, complex_number C) {
    return belong_to(std::real(c), R) && belong_to(std::imag(c), R);
}

template<typename BinOp, typename G>
concept associative = false;
template<typename BinOp, typename G>
concept with_identity = false;
template<typename BinOp, typename G>
concept with_inverse = false;

template<typename G, typename BinOp>
concept group =
        std::is_same_v<G, std::invoke_result_t<BinOp, G, G>> &&
        associative<BinOp, G> &&
        with_identity<BinOp, G> &&
        with_inverse<BinOp, G>;

}
