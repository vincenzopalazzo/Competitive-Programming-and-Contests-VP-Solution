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
#include "../src/core/NextLargerElement.hpp"

static void BM_Naive(benchmark::State& state)
{
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(state.range(0));
        for (int i = 0; i < state.range(0); i++)
            input.push_back(rand() % state.range(0));
        state.ResumeTiming();
        calc_next_larger_elem_naive(input);
    }
}

static void BM_Stack(benchmark::State& state)
{
    for(auto _ : state) {
        state.PauseTiming();
        std::vector<int> input;
        input.reserve(state.range(0));
        for (int i = 0; i < state.range(0); i++)
            input.push_back(rand() % state.range(0));
        state.ResumeTiming();
        calc_next_larger_elem_stack(input);
    }
}

BENCHMARK(BM_Naive)->Range(1<<10, 1<<18);
BENCHMARK(BM_Stack)->Range(1<<10, 1<<18);

BENCHMARK_MAIN();
