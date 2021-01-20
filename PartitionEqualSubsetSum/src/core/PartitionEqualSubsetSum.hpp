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
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include "../test/Utils.hpp"

const cpstl::Log LOG(false);

template <typename T>
static bool equal_sum_naive_recursion(std::vector<T> const &inputs, std::size_t index, T sum, T tot_sum)
{
        if (sum * 2 == tot_sum)
		return true;
	if (index >= inputs.size() || sum > tot_sum / 2)
		return false;

	auto with_current = equal_sum_naive_recursion(inputs, index++, sum + inputs[index], tot_sum);
	auto without_current = equal_sum_naive_recursion(inputs, index++, sum, tot_sum);
	return with_current || without_current;
}

template <typename T>
static bool equal_sum_in_the_vector(std::vector<T> const &inputs)
{
	if (inputs.empty()) return false; // I can not split.

	auto accumulator = 0;
	for (auto elem : inputs)
		accumulator += elem;
	// I can not split the accumulator in half and have
	// a same sum
	if(accumulator % 2 != 0)
		return false;

	return equal_sum_naive_recursion(inputs, 0, 0, accumulator);
}

template <typename T>
static bool equal_sum_hash_resursion(std::vector<T> const &inputs, std::size_t index, T sum, T tot_sum,
				     std::map<std::string, T> hash_mem)
{
	auto key = std::to_string(index) + std::to_string(sum);
	if (hash_mem.find(key) != hash_mem.end())
		return hash_mem[key];

	if (sum * 2 == tot_sum) {
		return true;
	}

	if (index >= inputs.size() || sum > tot_sum / 2)
		return false;

	auto with_elem = equal_sum_hash_resursion(inputs, index++, sum + inputs[index], tot_sum, hash_mem);
	auto without_elem = equal_sum_hash_resursion(inputs, index++, sum, tot_sum, hash_mem);
	auto result = with_elem || without_elem;
	key = std::to_string(index) + std::to_string(index);
	hash_mem[key] = result;
	return result;
}

template<typename T>
static bool equal_sum_in_the_vector_hash_dp(std::vector<T> const &inputs)
{
	auto accumulator = 0;
	for (auto elem : inputs)
		accumulator += elem;

	if (accumulator % 2 != 0) return false;

	std::map<std::string, T> hash_mem;
	return equal_sum_hash_resursion(inputs, 0, 0, accumulator, hash_mem);
}


template <typename T>
static bool equal_sum_matrix_mem(std::vector<T> const &inputs)
{
	auto accumulator = 0;
	for (auto elem : inputs)
		accumulator += elem;

	if (accumulator % 2 != 0) return false;

	std::vector<std::vector<bool>> mem(accumulator / 2 + 1, std::vector<bool>(inputs.size() + 1));

	for (int i = 0; i <= inputs.size(); i++)
		mem[0][i] = true;
	for (int i = 0; i <= accumulator / 2; i++)
		mem[i][0] = false;

	// bottom up approach
	for (int i = 1; i <= accumulator / 2; i++)
		for (int j = 1; j <= inputs.size(); j++) {
			mem[i][j] = mem[i][j - 1];
			if (i >= inputs[j - 1])
				mem[i][j] = mem[i][j] || mem[i - inputs[j - 1]][j - 1];
		}

	return mem[accumulator/2][inputs.size()];
}



template <typename T>
static bool equal_sum_vector_mem(std::vector<T> const &inputs)
{
	auto accumulator = 0;
	for (auto elem : inputs)
		accumulator += elem;

	if (accumulator % 2 != 0) return false;

	std::vector<bool> mem(accumulator / 2 + 1, false);
	for (std::size_t i = 0; i < inputs.size(); i++)
		for (std::size_t j = accumulator / 2; j >= inputs[i]; j--) {
			if (mem[j - inputs[i]] == true || j == inputs[i])
				mem[j] = true;
		}
	return mem[accumulator / 2];
}
