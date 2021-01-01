/**
 * Copyright (C) 2020  Vincenzo Palazzo vincenzopalazzodev@gmail.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include <vector>
#include <numeric>
#include "../test/Utils.hpp"

cpstl::Log LOG(false);

template<typename T, typename R>
R count_numbers_of_ways_prefix_sum(std::vector<T> const &inputs)
{
  R ways = 0;
  R sum_array = 0;
  for (auto elem : inputs)
    sum_array += elem;

  cpstl::cp_log(LOG, "The of the array is: " + std::to_string(sum_array));
  // If the sum of the items is a multiple of 3 we can keep going to search
  if (sum_array % 3 != 0) return 0;

  sum_array /= 3;
  R sum = 0;
  std::vector<int> tracking(inputs.size(), 0);
  for (int i = inputs.size() - 1; i >= 0; i--) {
    sum += inputs[i];
    if (sum == sum_array) {
      tracking[i] = 1;
    }
  }

  for (int i = inputs.size() - 2; i >= 0; i--)
      tracking[i] += tracking[i + 1];

  sum = 0;
  for (int i = 0; i + 2 < inputs.size(); i++) {
    sum += inputs[i];
    if (sum == sum_array) {
      ways += tracking[i + 2];
    }
  }

  return ways;
}
