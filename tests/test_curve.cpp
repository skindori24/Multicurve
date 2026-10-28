#include <gtest/gtest.h>

#include <vector>

#include "curve.hpp"

TEST(DiscountFactor, ZeroRateGivesOne) {
    EXPECT_DOUBLE_EQ(multicurve::discount_factor(0.0, 5.0), 1.0);
}

TEST(DiscountFactor, KnownValue) {
    // 10% for 2 years: 1 / (1 + 0.1 * 2) = 1 / 1.2
    EXPECT_NEAR(multicurve::discount_factor(0.10, 2.0), 1.0 / 1.2, 1e-12);
}

TEST(Bootstrap, OneDiscountFactorPerQuote) {
    const std::vector<multicurve::Quote> quotes = {{1.0, 0.15}, {2.0, 0.14}};
    const std::vector<double> result = multicurve::bootstrap(quotes);
    ASSERT_EQ(result.size(), 2u);
    EXPECT_GT(result[0], result[1]);  // longer maturity -> smaller discount factor
}
