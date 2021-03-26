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

template <typename T>
static std::size_t get_index_of_minimum(std::vector<T> const &inputs, std::size_t start) {
  auto min = inputs[start];
  auto index = start;
  for (std::size_t i = start + 1; i < inputs.size(); i++) {
    if (inputs[i] < min) {
      min = inputs[i];
      index = i;
    }
  }
  return index;
}

template <typename T>
static T reverse_function(std::vector<T> &to_reverse, std::size_t start, std::size_t end)
{

  auto i = start;
  auto j = end;
  while (i < j) {
    std::swap(to_reverse[i], to_reverse[j]);
    i++;
    j--;
  }

  auto result = (end - start) + 1;
  return result;
}

template <typename T>
static T revers_sort_computation(std::vector<T> &inputs)
{

  auto computation = 0;
  for (std::size_t i = 0; i < inputs.size() - 1; i++) {
    auto end = get_index_of_minimum(inputs, i);
    computation += reverse_function(inputs, i, end);
  }
  return computation;
}

int main() {
    int T, N;
    scanf("%d", &T);

    for (auto i = 1; i <= T; i++) {
      scanf("%d", &N);
      std::vector<int> inputs;
      inputs.reserve(N);
      //Read the array
      for (std::size_t t = 0; t < N; t++) {
        int value;
        scanf("%d", &value);
        inputs.push_back(value);
      }

      auto result = revers_sort_computation(inputs);
      std::cout << "Case #" << i << ": " << result << "\n";
    }
    return 0;
}
