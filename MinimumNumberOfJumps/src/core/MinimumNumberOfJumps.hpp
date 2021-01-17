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
	std::vector<T> jumps_mem(inputs.size(), INT32_MAX);
	std::vector<T> from_pos(inputs.size(), 0);
	jumps_mem[0] = 0;
	for (std::size_t i = 1; i < inputs.size(); i++) {
		for (std::size_t j = 0; j < i; j++) {
			if (jumps_mem[i] > jumps_mem[j] + 1) {
				from_pos[i] = j;
				jumps_mem[i] = jumps_mem[j] + 1;
			}
		}
	}

	return jumps_mem[inputs.size() - 1];
}
