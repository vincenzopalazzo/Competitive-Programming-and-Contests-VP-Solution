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

#ifndef KADANE_ALG_HPP
#define KADANE_ALG_HPP

#include<vector>

/**
 * Kadane's Algorithm implementation with only two point.
 *
 * - The time complexity of this solution is O(N)
 * - The space complexity of the solution is O(1)
 * (or O(N) if you consider the input)
 */
template<typename T, typename R = long>
R kadane_algorithm_pointer(std::vector<T> const &input)
{
  R max_elem = INT32_MIN;
  R max_tmp = 0;
  for (auto elem: input) {
    max_tmp += elem;
    if (max_elem < max_tmp) {
      max_elem = max_tmp;
    }
    if (max_tmp < 0)
      max_tmp = 0;
  }
  return max_elem;
}

/**
 * Implementing the Kadane’s Algorithm, with a vector
 * and the dynamic programming.
 *
 * - Time complexity is O(N), because we need to iterate over N
 * - The space complexity is O(N) because we use another array of size N,
 * considering the input array the space complexity is O(N ^ 2);
 */
template<typename T = int, typename R = long>
R kadane_algorithm_dp(std::vector<T> const &input)
{
  auto dp = std::vector<R>(input.size(), 0);
  dp[0] = input[0];
  auto max = dp[0];

  for (std::size_t i = 1; i < input.size(); i++) {
    auto local_max = dp[i - 1] + input[i];
    dp[i] = std::max(local_max, input[i]);
    max = std::max(max, dp[i]);
  }

  return max;
}

#endif
