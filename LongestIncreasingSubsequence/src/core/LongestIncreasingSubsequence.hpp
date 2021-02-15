
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
#include "../test/Utils.hpp"
#include <vector>

const cpstl::Log LOG(false);

template <typename T, typename R>
R _lis_dynamic_programming(std::vector<T> const &input, std::size_t pos, R &max)
{

	if (pos == 1)
		return 1;
	R res, max_ending_here = 1;

	for (std::size_t i = 1; i < pos; i++) {
		res = _lis_dynamic_programming(input, i, max);
		if (input[i - 1] < input[pos - 1] && pos + 1 > max) {
			max_ending_here = res + 1;
		}
	}

	if (max < max_ending_here) {
		max = max_ending_here;
	}
	return max_ending_here;
}

template <typename T, typename R>
R lis_dynamic_programming(std::vector<T> const &input)
{
	R max = 1;
	_lis_dynamic_programming<T, R>(input, input.size(), max);
	return max;
}

template <typename T, typename R>
R lis_dynamic_programming_with_mem(std::vector<T> const &input)
{
	std::vector<T> mem(input.size(), 1);
	for (std::size_t i = 0; i < input.size(); i++) {
		for (std::size_t j = 0; j < i; j++) {
			if (input[j] < input[i]) {
				mem[i] = std::max(mem[i], mem[j] + 1);
			}
		}
	}
	R lis = mem[0];
	for (std::size_t i = 0; i < input.size(); i++) {
		lis = std::max(lis, mem[i]);
	}
	return lis;
}

// Source https://stackoverflow.com/a/2631810/10854225
template <typename T, typename R>
R lis_dynamic_programming_bst(std::vector<T> const &inputs)
{
	auto INT_INFINITY = 1e9;
	std::vector<T> dp_mem(inputs.size() + 1, INT_INFINITY);
	dp_mem[0] = -INT_INFINITY;
	for (std::size_t i = 0; i < inputs.size(); i++) {
		auto element = inputs[i];
		auto greater_elem =
		    std::upper_bound(dp_mem.begin(), dp_mem.end(), element) -
		    dp_mem.begin(); // Get the index of element
		if (dp_mem[greater_elem - 1] < element &&
		    element < dp_mem[greater_elem])
			dp_mem[greater_elem] = element;
	}

	auto result = 0;
	for (std::size_t i = 0; i <= inputs.size(); i++) {
		auto elem = dp_mem[i];
		if (elem < INT_INFINITY)
			result = i;
	}
	return result;
}

/**
 * For this implementation I will use the code implemented inside this method
 * "lis_dynamic_programming_with_mem" but with the geeksforgeeks interface,
 * describer here.
 */

inline int longestSubsequence(int n, int a[])
{
	std::vector<int> mem(n, 1);
	for (std::size_t i = 0; i < n; i++) {
		for (std::size_t j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				mem[i] = std::max(mem[i], mem[j] + 1);
			}
		}
	}
	int lis = mem[0];
	for (std::size_t i = 0; i < n; i++) {
		lis = std::max(lis, mem[i]);
	}
	return lis;
}
