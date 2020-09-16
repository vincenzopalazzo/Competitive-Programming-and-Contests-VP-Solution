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
    }
}

static void BM_Balance_Tree_SOL_K3(benchmark::State& state) {
    int k = 3;
    for(auto _ : state) {
        state.PauseTiming();
        int input[state.range(0)];
        for (int i = 0; i < state.range(0); i++)
            input[i] = rand() % state.range(0);
        const int size_array = sizeof(input) / sizeof(input[0]);
        state.ResumeTiming();
        std::vector<int> result = max_sub_array_bbst_sol(input, size_array, k);
    }
}

static void BM_FIFO_QUEUE_SOL_K3(benchmark::State& state) {
    int k = 12;
    int startTime;
    int endTime;
    for(auto _ : state) {
        state.PauseTiming();
        int input[state.range(0)];
        for (int i = 0; i < state.range(0); i++)
            input[i] = rand() % state.range(0);
        const int size_array = sizeof(input) / sizeof(input[0]);
        state.ResumeTiming();
        std::vector<int> result = max_sub_array_deck_sol(input, size_array, k);
    }
}

BENCHMARK(BM_NAIVE_SOL_K3)->Range(1<<10, 1<<18);
BENCHMARK(BM_Balance_Tree_SOL_K3)->Range(1<<10, 1<<18);
BENCHMARK(BM_FIFO_QUEUE_SOL_K3)->Range(1<<10, 1<<18);

BENCHMARK_MAIN();