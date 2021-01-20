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
T min(T x, T y, T z)
{
	return std::min(std::min(x, y), z);
}

template <typename T>
static T number_of_operation_into_str(std::string const &string_one,
				      std::string const &string_two)
{
	std::vector<std::vector<T>> mem(string_one.size() + 1,
					std::vector<T>(string_two.size() + 1, 0));

	//Init the first line
	for (std::size_t i = 1; i <= string_one.size(); i++)
		mem[i][0] = i;
	for (std::size_t i = 1; i <= string_two.size(); i++)
		mem[0][i] = i;

	for (std::size_t i = 1; i <= string_one.size(); i++) {
		for (std::size_t j = 1; j <= string_two.size(); j++) {
		        if (string_one[i - 1] == string_two[j - 1]) {
				mem[i][j] = mem[i - 1][j - 1];
			} else {
				auto upper_elem = mem[i][j - 1]; // insert operation
				auto prev_elem = mem[i - 1][j]; // Remove operation
				auto diagonal = mem[i - 1][j - 1]; // Replace
				mem[i][j] = 1 + min(upper_elem, prev_elem, diagonal);
			}

		}
	}

	return mem[string_one.size()][string_two.size()];
}
