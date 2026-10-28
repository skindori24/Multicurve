/**
 * @file curve.hpp
 * @brief Multicurve bootstrapping, version 0.1 (simplified placeholder).
 *
 * The finished project will build an OIS discount curve and a 3M forward curve
 * from market quotes. This first version only turns deposit quotes into
 * discount factors.
 */
#pragma once

#include <vector>

namespace multicurve {

/// Market quote of a deposit.
struct Quote {
    double maturity;  ///< Maturity in years.
    double rate;      ///< Simple interest rate as a decimal (0.15 means 15%).
};

/**
 * @brief Discount factor of a deposit: P = 1 / (1 + rate * maturity).
 * @param rate simple interest rate as a decimal
 * @param maturity maturity in years
 * @return discount factor between 0 and 1 for positive rates
 */
double discount_factor(double rate, double maturity);

/**
 * @brief Simplified bootstrap: one discount factor per quote.
 *
 * Placeholder for the real multicurve algorithm, which will solve the curves
 * instrument by instrument.
 * @param quotes deposit quotes
 * @return discount factors in the same order as the quotes
 */
std::vector<double> bootstrap(const std::vector<Quote>& quotes);

}  // namespace multicurve
