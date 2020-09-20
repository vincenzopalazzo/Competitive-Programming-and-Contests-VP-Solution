//
// Created by vincent on 9/18/20.
//
#include <benchmark/benchmark.h>
#include "../src/core/NextLargerElement.h"

static void BM_Template(benchmark::State& state)
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


BENCHMARK(BM_Template)->Range(1<<10, 1<<18);

BENCHMARK_MAIN();
