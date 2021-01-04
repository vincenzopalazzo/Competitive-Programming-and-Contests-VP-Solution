//
// Created by vincent on 9/18/20.
//
#include <benchmark/benchmark.h>
#include "../src/core/LittleGirlAndMaximumSum.hpp"

static void BM_FENWICK_TREE(benchmark::State& state)
{
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(state.range(1));
        for (size_t i = 0; i < state.range(1); i++)
            input.push_back(rand() % state.range(1));
        std::vector<std::pair<int, int>> queries;
        for (size_t i = 0; i < state.range(0); i++)
            queries.emplace_back(rand() % state.range(1), rand() % state.range(1));
        state.ResumeTiming();
        max_sum_of_queries_fenwick_tree(input, queries);
    }
}

static void BM_PREFIX_SUM(benchmark::State& state)
{
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(state.range(1));
        for (size_t i = 0; i < state.range(1); i++)
            input.push_back(rand() % state.range(1));
        std::vector<std::pair<int, int>> queries;
        for (size_t i = 0; i < state.range(0); i++)
            queries.emplace_back(rand() % state.range(1), rand() % state.range(1));
        state.ResumeTiming();
        max_sum_of_queries(input, queries);
    }
}

static void custom_arguments(benchmark::internal::Benchmark* b);

BENCHMARK(BM_PREFIX_SUM)->Apply(custom_arguments);
BENCHMARK(BM_FENWICK_TREE)->Apply(custom_arguments);

BENCHMARK_MAIN();

static void custom_arguments(benchmark::internal::Benchmark* b)
{
    for (int i = 10; i <= 25; i++)
        b->Args({static_cast<long>(std::pow(2, i)), static_cast<long>(std::pow(2, 30))});
}

