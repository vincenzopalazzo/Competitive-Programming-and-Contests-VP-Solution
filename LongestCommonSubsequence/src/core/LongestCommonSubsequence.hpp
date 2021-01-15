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

const cpstl::Log LOG(true);

template <typename T>
static T find_long_common_subsequences(std::string const &seq_one,
                                       std::string const &seq_two)
{
 	std::vector<std::vector<T>> mem_matrix(seq_one.length() + 1, std::vector<T>(seq_two.length() + 1));
        for (std::size_t col = 1; col <= seq_one.length(); col++) {
		for (std::size_t row = 1; row <= seq_two.length(); row++) {
			if (seq_one[col - 1] == seq_two[row - 1]) {
				//Take the diagonal
				mem_matrix[col][row] = mem_matrix[col - 1][row - 1] + 1;
			} else {
				//Take the maximum from the left and side
				auto max_val = std::max(mem_matrix[col - 1][row], mem_matrix[col][row - 1]);
				mem_matrix[col][row] = max_val;
			}
		}
	}
	return mem_matrix[seq_one.length()][seq_two.length()];;
}
