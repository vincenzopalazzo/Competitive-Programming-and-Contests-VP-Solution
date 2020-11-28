//
// Created by vincent on 9/16/20.
//
#include <vector>
#include <cstdlib>
#include <cmath>
#include <benchmark/benchmark.h>
#include "../src/core/MonkeyAndBamboo.h"

static void BM_BISECTION(benchmark::State& state)
{
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(state.range(0));
        for (int i = 0; i < state.range(0); i++)
            input.push_back(rand() % state.range(0));
        state.ResumeTiming();
        int res = estimate_dimension_k_bisection<int, int>(input);
    }
}

static void BM_SUBTRACTION(benchmark::State& state)
{
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(state.range(0));
        for (int i = 0; i < state.range(0); i++)
            input.push_back(rand() % state.range(0));
        state.ResumeTiming();
        auto maximum_house = estimate_dimension_k_subtraction<int, int>(input);
    }
}

static void BM_SORT(benchmark::State& state)
{
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(state.range(0));
        for (int i = 0; i < state.range(0); i++)
            input.push_back(rand() % state.range(0));
        state.ResumeTiming();
        auto maximum_house = estimate_dimension_k_trivial<int, int>(input);
    }
}

static void custom_arguments(benchmark::internal::Benchmark* b);

BENCHMARK(BM_BISECTION)->Apply(custom_arguments);
BENCHMARK(BM_SUBTRACTION)->Apply(custom_arguments);
BENCHMARK(BM_SORT)->Apply(custom_arguments);

BENCHMARK_MAIN();

static void custom_arguments(benchmark::internal::Benchmark* b)
{
    for (int i = 10; i <= 21; i++)
        b->Args({static_cast<long>(std::pow(2, i))});
}