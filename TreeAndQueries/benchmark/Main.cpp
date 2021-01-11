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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include <benchmark/benchmark.h>
#include <cmath>
#include "../src/core/TreeAndQueries.hpp"

static void BM_NAIVE_SOLUTION(benchmark::State& state)
{
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(state.range(1));
        for (size_t i = 0; i < state.range(1); i++)
            input.push_back(rand() % state.range(1));
        state.ResumeTiming();

        solution(input);
    }
}

static void custom_arguments(benchmark::internal::Benchmark* b);

BENCHMARK(BM_NAIVE_SOLUTION)->Apply(custom_arguments);

BENCHMARK_MAIN();

static void custom_arguments(benchmark::internal::Benchmark* b)
{
    for (int i = 2; i <= 14; i++)
        b->Args({static_cast<long>(std::pow(2, i)), static_cast<long>(std::pow(2, 21))});
}

