//
// Created by vincent on 9/16/20.
//
#include <vector>
#include <cstdlib>
#include <cmath>
#include <benchmark/benchmark.h>
#include "../src/core/MaxSubArrayPos.h"

static void BM_NAIVE_SOL(benchmark::State& state)
{
    int k = state.range(0);
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(state.range(1));
        for (int i = 0; i < state.range(1); i++)
            input.push_back(rand() % state.range(1));
        state.ResumeTiming();
        std::vector<int> result = max_sub_array_naive_sol(input, k);
    }
}

static void BM_Balance_Tree_SOL(benchmark::State& state)
{
    int k = state.range(0);
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(state.range(1));
        for (int i = 0; i < state.range(1); i++)
            input.push_back(rand() % state.range(1));
        state.ResumeTiming();
        std::vector<int> result = max_sub_array_bbst_sol(input, k);
    }
}

static void BM_RB_Tree_SOL(benchmark::State& state)
{
    int k = state.range(0);
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(state.range(1));
        for (int i = 0; i < state.range(1); i++)
            input.push_back(rand() % state.range(1));
        state.ResumeTiming();
        std::vector<int> result = max_sub_array_pure_rbt_sol(input, k);
    }
}

static void BM_FIFO_QUEUE_SOL(benchmark::State& state)
{
    int k = state.range(0);
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(state.range(1));
        for (long i = 0; i < state.range(1); i++)
            input.push_back(rand() % state.range(1));
        state.ResumeTiming();
        std::vector<int> result = max_sub_array_deck_sol(input, k);
    }
}

static void custom_arguments(benchmark::internal::Benchmark* b);

BENCHMARK(BM_NAIVE_SOL)->Apply(custom_arguments);
BENCHMARK(BM_Balance_Tree_SOL)->Apply(custom_arguments);
//BENCHMARK(BM_RB_Tree_SOL)->Apply(custom_arguments);
BENCHMARK(BM_FIFO_QUEUE_SOL)->Apply(custom_arguments);

BENCHMARK_MAIN();

static void custom_arguments(benchmark::internal::Benchmark* b)
{
    for (int i = 2; i <= 14; i++)
            b->Args({static_cast<long>(std::pow(2, i)), static_cast<long>(std::pow(2, 21))});
}