//
// Created by vincent on 9/18/20.
//
#include <benchmark/benchmark.h>
#include "../src/core/NextLargerElement.h"

static void BM_Naive(benchmark::State& state)
{
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(state.range(0));
        for (int i = 0; i < state.range(0); i++)
            input.push_back(rand() % state.range(0));
        state.ResumeTiming();
        calc_next_larger_elem_naive(input);
    }
}

static void BM_Stack(benchmark::State& state)
{
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(state.range(0));
        for (int i = 0; i < state.range(0); i++)
            input.push_back(rand() % state.range(0));
        state.ResumeTiming();
        calc_next_larger_elem_stack(input);
    }
}

BENCHMARK(BM_Naive)->Range(1<<10, 1<<18);
BENCHMARK(BM_Stack)->Range(1<<10, 1<<18);

BENCHMARK_MAIN();
