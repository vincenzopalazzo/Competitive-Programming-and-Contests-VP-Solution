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
#include "../test/Utils.hpp"

const cpstl::Log LOG(false);

template <typename T>
static T minimize_jump_to_reach_end(std::vector<T> const &inputs)
{
	if (inputs.empty()) return 0;
	if (inputs[0] == 0) return -1;
	std::vector<T> jumps_mem(inputs.size(), INT32_MAX);
	std::vector<T> from_pos(inputs.size(), 0);
	jumps_mem[0] = 0;
	for (std::size_t i = 1; i < inputs.size(); i++) {
		for (std::size_t j = 0; j < i; j++) {
			if (i <= j + inputs[j] && jumps_mem[i] > jumps_mem[j] + 1) {
				from_pos[i] = j;
				jumps_mem[i] = jumps_mem[j] + 1;
			}
		}
	}
	auto result = (jumps_mem[jumps_mem.size() - 1] == INT32_MAX)
		? -1 : jumps_mem[jumps_mem.size() - 1];
	return result;
}

template<typename T>
static T optimize_minimum_jump_to_reach_end(std::vector<T> const &inputs)
{
	if (inputs.empty()) return 0;
	if (inputs[0] == 0) { return -1;}
	T max_reach = inputs[0];
	T steps = inputs[0];
	T jumps = 1;
	for (T i = 1; i < inputs.size(); i++) {
		if (i == inputs.size() - 1) {
			return jumps;
		}
		max_reach = std::max(max_reach, i + inputs[i]);
		steps--;
		if (steps == 0) {
			jumps++;
			if (i > max_reach) {
				return -1;
			}
			steps = max_reach - i;
		}
	}
	return -1;
}
