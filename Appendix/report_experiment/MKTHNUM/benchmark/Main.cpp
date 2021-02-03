/**
 * Competitive-Programming-and-Contests-VP-Solution a collection of
 * code with an engineering approach to solve the problem.
 * https://github.com/vincenzopalazzo/Competitive-Programming-and-Contests-VP-Solution
 *
 * Copyright (C) 2020-2021  Vincenzo Palazzo vincenzopalazzodev@gmail.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */
#include <benchmark/benchmark.h>

#include <cmath>

#include "../src/core/MKthNum.hpp"

static void BM_CUSTOM_SEGMENT_TREE(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    std::vector<long long> input;
    input.reserve(state.range(1));
    for (size_t i = 0; i < state.range(1); i++)
      input.push_back(rand() % state.range(1));
    std::vector<Query<long long>> queries;
    for (size_t i = 0; i < state.range(0); i++) {
      auto start = rand() % state.range(1);
      auto end = rand() % state.range(1);
      auto kth = std::max(start, end) - std::min(start, end);
      queries.emplace_back(std::min(start, end), std::max(start, end), kth);
    }
    state.ResumeTiming();
    auto result = get_kth_number_segment_tree<long long>(input, queries);
  }
}

static void BM_PERSISTENT_SEGMENT_TREE(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    std::vector<std::pair<long long, std::size_t>> input;
    input.reserve(state.range(1));
    for (size_t i = 0; i < state.range(1); i++)
      input.push_back({rand() % state.range(1), i});
    std::vector<Query<long long>> queries;
    for (size_t i = 0; i < state.range(0); i++) {
      auto start = rand() % state.range(1);
      auto end = rand() % state.range(1);
      auto kth = std::max(start, end) - std::min(start, end);
      queries.emplace_back(std::min(start, end), std::max(start, end), kth);
    }
    state.ResumeTiming();
    auto result = get_kth_number_persistent_segtree<long long>(input, queries);
  }
}

static void custom_arguments(benchmark::internal::Benchmark* b);

BENCHMARK(BM_CUSTOM_SEGMENT_TREE)->Apply(custom_arguments);
BENCHMARK(BM_PERSISTENT_SEGMENT_TREE)->Apply(custom_arguments);

BENCHMARK_MAIN();

static void custom_arguments(benchmark::internal::Benchmark* b) {
  for (int i = 2; i <= 14; i++)
    b->Args({static_cast<long>(std::pow(2, i)),
             static_cast<long>(std::pow(2, 21))});
}
