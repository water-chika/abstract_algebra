#include <abstract_algebra.hpp>
#include <iostream>

int main() {
    float x = 7.0;
    using namespace abstract_algebra;
    if (belong_to(x, N)) {
        std::cout << x << " belong to N" << std::endl;
    }
    std::complex<double> c = 7.0;
    if (belong_to(c, N)) {
        std::cout << c << " belong to N" << std::endl;
    }
    return 0;
}

