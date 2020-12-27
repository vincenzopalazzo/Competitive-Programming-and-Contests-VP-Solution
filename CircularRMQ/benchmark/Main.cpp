//
// Created by vincent on 9/18/20.
//
#include <benchmark/benchmark.h>
#include "../src/core/CircularRMQ.h"

static void RoundRMQSegmentTreeBM(benchmark::State& state)
{
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(state.range(1));
        for (size_t i = 0; i < state.range(1); i++)
            input.push_back(rand() % state.range(1));
        std::vector<Query<int>> queries;
        for (size_t i = 0; i < state.range(0); i++)
            if (i % 2 == 0)
                queries.emplace_back(rand() % state.range(1), rand() % state.range(1));
            else
                queries.emplace_back(rand() % state.range(1), rand() % state.range(1), rand() % state.range(1), true);
        state.ResumeTiming();
        auto segment_tree = cpstl::SegmentTree<int>(input);
        std::vector<int> result = calculate_minimum_rmq_query(segment_tree, queries);
    }
}

static void RoundRMQLazySegmentTreeBM(benchmark::State& state)
{
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(state.range(1));
        for (size_t i = 0; i < state.range(1); i++)
            input.push_back(rand() % state.range(1));
        std::vector<Query<int>> queries;
        for (size_t i = 0; i < state.range(0); i++)
            if (i % 2 == 0)
                queries.emplace_back(rand() % state.range(1), rand() % state.range(1));
            else
                queries.emplace_back(rand() % state.range(1), rand() % state.range(1), rand() % state.range(1), true);
        state.ResumeTiming();
        auto segment_tree = cpstl::LazySegmentTree<int>(input);
        std::vector<int> result = calculate_minimum_rmq_query_lazy(segment_tree, queries);
    }
}

static void custom_arguments(benchmark::internal::Benchmark* b);

BENCHMARK(RoundRMQSegmentTreeBM)->Apply(custom_arguments);
BENCHMARK(RoundRMQLazySegmentTreeBM)->Apply(custom_arguments);

BENCHMARK_MAIN();

static void custom_arguments(benchmark::internal::Benchmark* b)
{
    for (int i = 2; i <= 14; i++)
        b->Args({static_cast<long>(std::pow(2, i)), static_cast<long>(std::pow(2, 21))});
}

