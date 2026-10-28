#include <benchmark/benchmark.h>

#include <cstdint>
#include <vector>

#include "curve.hpp"

// Measures how fast bootstrap() turns N quotes into discount factors.
static void BM_Bootstrap(benchmark::State& state) {
    std::vector<multicurve::Quote> quotes;
    for (std::int64_t i = 1; i <= state.range(0); ++i) {
        quotes.push_back({0.25 * static_cast<double>(i), 0.15});
    }
    for (auto _ : state) {
        std::vector<double> result = multicurve::bootstrap(quotes);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_Bootstrap)->Arg(10)->Arg(100)->Arg(1000);

BENCHMARK_MAIN();
