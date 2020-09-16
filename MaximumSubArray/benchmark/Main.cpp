//
// Created by vincent on 9/16/20.
//
#include <vector>
#include <cstdlib>
#include <benchmark/benchmark.h>
#include "../src/core/MaxSubArrayPos.h"

static void BM_NAIVE_SOL_K3(benchmark::State& state) {
    int k = 3;
    for(auto _ : state) {
        state.PauseTiming();
        int input[state.range(0)];
        for (int i = 0; i < state.range(0); i++)
            input[i] = rand() % state.range(0);
        const int size_array = sizeof(input) / sizeof(input[0]);
        state.ResumeTiming();
        std::vector<int> result = max_sub_array_naive_sol(input, size_array, k);
        benchmark::DoNotOptimize(result.data());
        benchmark::ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_NAIVE_SOL_K3)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);;

BENCHMARK_MAIN();