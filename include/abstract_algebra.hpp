#pragma once

#include <type_traits>
#include <concepts>

namespace abstract_algebra {

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
