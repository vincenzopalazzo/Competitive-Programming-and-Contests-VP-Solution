//
// Created by vincent on 9/18/20.
//
#include <benchmark/benchmark.h>
#include "../src/core/TwoNumberSum.hpp"

static void BM_TWO_FOR(benchmark::State& state)
{
  state.PauseTiming();
  std::vector<int> input;
  input.reserve(state.range(0));
  for (size_t i = 0; i < state.range(0); i++)
    input.push_back(rand() % state.range(0));
  state.ResumeTiming();
  get_element_to_get_sum(input, rand());
}

static void BM_HASH_TB(benchmark::State& state)
{
  state.PauseTiming();
  std::vector<int> input;
  input.reserve(state.range(0));
  for (size_t i = 0; i < state.range(0); i++)
    input.push_back(rand() % state.range(0));
  state.ResumeTiming();
  get_element_to_get_sum_hasttb(input, rand());
}

static void BM_SORT(benchmark::State& state)
{
  state.PauseTiming();
  std::vector<int> input;
  input.reserve(state.range(0));
  for (size_t i = 0; i < state.range(0); i++)
    input.push_back(rand() % state.range(0));
  state.ResumeTiming();
  get_element_to_get_sum_two_pointer(input, rand());
}

BENCHMARK(BM_TWO_FOR)->Range(1<<18, 1<<21);
BENCHMARK(BM_HASH_TB)->Range(1<<18, 1<<21);
BENCHMARK(BM_SORT)-> Range(1<<18, 1<<21);

BENCHMARK_MAIN();

