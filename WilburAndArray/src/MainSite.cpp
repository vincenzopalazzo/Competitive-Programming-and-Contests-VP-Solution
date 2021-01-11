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
#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename R>
static R get_minimum_number_of_step(std::vector<T> const &inputs)
{
    if (inputs.empty()) return 0;
    R steps = 0;
    steps += std::abs(inputs[0]);
    for (std::size_t i = 1; i < inputs.size(); i++) {
        steps += std::abs(inputs[i] - inputs[i - 1]);
    }
    return steps;
}

int main() {
    int N;
    scanf("%d", &N);

    std::vector<long long> inputs;
    inputs.reserve(N);
    //Read the array
    for (std::size_t t = 0; t < N; t++) {
        long long value;
        scanf("%lld", &value);
        inputs.push_back(value);
    }
    auto result = get_minimum_number_of_step<long long, long long>(inputs);
    printf("%lld\n", result);
}
