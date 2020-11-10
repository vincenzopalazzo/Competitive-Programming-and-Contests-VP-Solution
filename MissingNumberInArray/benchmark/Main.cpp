//
// Created by vincent on 9/18/20.
//
#include <benchmark/benchmark.h>
#include "../src/core/MissingNumberInArray.h"

static void BM_BITWISE(benchmark::State& state)
{
    int k = state.range(0);
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(k);
        for (long i = 1; i <= k; i++)
            input.push_back(i);
        state.ResumeTiming();
        get_missing_number_bitmagic(input, k);
    }
}

static void BM_SUM(benchmark::State& state)
{
    int k = state.range(0);
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(k);
        for (long i = 1; i <= k; i++)
            input.push_back(i);
        state.ResumeTiming();
        get_missing_number_with_sum(input, k);
    }
}

static void BM_TOT_SUM(benchmark::State& state)
{
    int k = state.range(0);
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(k);
        for (long i = 1; i <= k; i++)
            input.push_back(i);
        state.ResumeTiming();
        get_missing_number_formula(input, k);
    }
}


BENCHMARK(BM_BITWISE)->Range(8, 8<<10);
BENCHMARK(BM_SUM)->Range(8, 8<<10);
BENCHMARK(BM_TOT_SUM)->Range(8, 8<<10);

BENCHMARK_MAIN();

