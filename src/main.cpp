/**
 * @file main.cpp
 * @brief Prints discount factors for a few sample deposit quotes.
 */
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <vector>

#include "curve.hpp"

int main() {
    const std::vector<multicurve::Quote> quotes = {
        {0.25, 0.160}, {0.5, 0.155}, {1.0, 0.150}, {2.0, 0.141}, {5.0, 0.131}};
    const std::vector<double> discount_factors = multicurve::bootstrap(quotes);

    std::cout << "maturity,Y   rate,%   discount factor\n" << std::fixed;
    for (std::size_t i = 0; i < quotes.size(); ++i) {
        std::cout << std::setprecision(2) << std::setw(10) << quotes[i].maturity
                  << std::setw(9) << quotes[i].rate * 100.0 << std::setprecision(6)
                  << std::setw(18) << discount_factors[i] << '\n';
    }
    return 0;
}
