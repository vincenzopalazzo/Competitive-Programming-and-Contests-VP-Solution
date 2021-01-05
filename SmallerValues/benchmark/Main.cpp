//
// Created by vincent on 9/18/20.
//
#include <benchmark/benchmark.h>

static void BM_Template(benchmark::State& state)
{
}

static void custom_arguments(benchmark::internal::Benchmark* b);

BENCHMARK(BM_Template)->Apply(custom_arguments);

BENCHMARK_MAIN();

static void custom_arguments(benchmark::internal::Benchmark* b)
{}

