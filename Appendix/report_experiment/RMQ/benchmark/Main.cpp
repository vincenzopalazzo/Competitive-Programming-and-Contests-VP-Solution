//
// Created by vincent on 9/18/20.
//
#include <benchmark/benchmark.h>
#include <cmath>
#include "../src/core/RangeMinimumQuery.hpp"

//TODO the naive solution include only the range minimum query answer without update
//for the moment
static void BM_NAIVE_SOLUTION(benchmark::State& state)
{
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(state.range(1));
        for (size_t i = 0; i < state.range(1); i++)
            input.push_back(rand() % state.range(1));
        std::vector<Query<int>> queries;
        for (size_t i = 0; i < state.range(0); i++)
            queries.emplace_back(false, rand() % state.range(1), rand() % state.range(1));
        state.ResumeTiming();
        std::vector<int> result = range_minimum_query_naive(input, queries);
    }
}

static void BM_NAIVE_SEGMENT_TREE_BH(benchmark::State& state)
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
                queries.emplace_back(false, rand() % state.range(1), rand() % state.range(1));
            else
                queries.emplace_back(false, rand() % state.range(1), rand() % state.range(1));
        state.ResumeTiming();
        auto segment_tree = cpstl::SegmentTree<int>(input);
        std::vector<int> result = range_minimum_query_segment_tree(segment_tree, queries);
    }
}

static void BM_NAIVE_LAZY_SEGMENT_TREE_BH(benchmark::State& state)
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
                queries.emplace_back(false, rand() % state.range(1), rand() % state.range(1));
            else
                queries.emplace_back(false, rand() % state.range(1), rand() % state.range(1));
        state.ResumeTiming();
        auto segment_tree = cpstl::LazySegmentTree<int>(input);
        std::vector<int> result = range_minimum_query_lazy_segment_tree(segment_tree, queries);
    }
}

static void custom_arguments(benchmark::internal::Benchmark* b);

BENCHMARK(BM_NAIVE_SOLUTION)->Apply(custom_arguments);
BENCHMARK(BM_NAIVE_SEGMENT_TREE_BH)->Apply(custom_arguments);
BENCHMARK(BM_NAIVE_LAZY_SEGMENT_TREE_BH)->Apply(custom_arguments);

BENCHMARK_MAIN();

static void custom_arguments(benchmark::internal::Benchmark* b)
{
    for (int i = 2; i <= 14; i++)
        b->Args({static_cast<long>(std::pow(2, i)), static_cast<long>(std::pow(2, 21))});
}

