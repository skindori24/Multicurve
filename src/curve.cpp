#include "curve.hpp"

namespace multicurve {

double discount_factor(double rate, double maturity) { return 1.0 / (1.0 + rate * maturity); }

std::vector<double> bootstrap(const std::vector<Quote>& quotes) {
    std::vector<double> discount_factors;
    discount_factors.reserve(quotes.size());
    for (const Quote& quote : quotes) {
        discount_factors.push_back(discount_factor(quote.rate, quote.maturity));
    }
    return discount_factors;
}

}  // namespace multicurve
