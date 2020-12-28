//
// Created by vincent on 9/18/20.
//
#include <benchmark/benchmark.h>
#include "../src/core/FibonacciNum.h"

static void BM_FIB_NAIVE(benchmark::State& state)
{
    for (auto _ : state) {
        for (int i = state.range(0); i--; )
            fibonacci_num(i);
    }
}

static void BM_FIB_MEM(benchmark::State& state)
{
    for (auto _ : state) {
        for (int i = state.range(0); i--; )
            fibonacci_num_mem(i);
    }
}

static void BM_FIB_TAB(benchmark::State& state)
{
    for (auto _ : state) {
        for (int i = state.range(0); i--; )
            fibonacci_num_tab(i);
    }
}


BENCHMARK(BM_FIB_NAIVE)->Range(1<<0, 1<<10);

BENCHMARK_MAIN();

