#include <abstract_algebra.hpp>
#include <functional>

    template<>
    concept associative<std::plus<int>, int> = false;
    template<>
    concept with_identity<std::plus<int>, int> = false;
    template<>
    concept with_inverse<std::plus<int>, int> = false;

int main() {

    return 0;
}