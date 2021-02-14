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
#include <cstdlib>
#include <string>
#include <vector>

const cpstl::Log LOG(false);

template <typename T>
static void vertex_covered(std::vector<std::vector<T>> const &vertices, T vertex,
			   T parent, std::vector<std::vector<T>> &dp_mem)
{
	for (auto const &next : vertices[vertex]) {
		if (next == parent) continue;
		vertex_covered(vertices, next, vertex, dp_mem);
		dp_mem[0][vertex] += dp_mem[1][next];
		dp_mem[1][vertex] += std::min(dp_mem[0][next], dp_mem[1][next]);
	}
	dp_mem[1][vertex]++;
}

template <typename T>
static T number_of_vertex_in_the_tree(std::vector<std::vector<T>> const &vertices)
{
	std::vector<std::vector<T>> dp_mem(2, std::vector<T>(vertices.size(), 0));
	vertex_covered(vertices, 0, -1, dp_mem);
	return std::min(dp_mem[0][0], dp_mem[1][0]);
}
