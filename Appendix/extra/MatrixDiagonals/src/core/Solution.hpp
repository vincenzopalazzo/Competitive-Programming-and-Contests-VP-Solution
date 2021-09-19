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
#include <functional>
#include <string>
#include <vector>

const cpstl::Log LOG(true);

static bool check_bound(std::size_t row_size, std::size_t col_size,
			std::size_t row, std::size_t col)
{
	return row < 0 || row > row_size || col < 0 || col > col_size;
}

static bool walk_up(std::size_t row_size, std::size_t col_size,
		    std::size_t &row, std::size_t &col)
{

	if (col == 0 || row >= row_size) {
		// we are at the end of the matrix
		// we need to check the col
		if (row >= row_size)
			col++;
		else
			row++;
		return false; // we don't need to go up now
	}
	// continue to walk
	row++, col--;
	return true;
}

static bool walk_down(std::size_t row_size, std::size_t col_size,
		      std::size_t &row, std::size_t &col)
{

	if (row == 0 || col >= col_size) {
		if (col >= col_size)
			row++;
		else
			col++;
		return true; // we need to going up;
	}
	// continue to walk
	row--, col++;
	return false;
}

template <typename T>
static std::vector<T> zig_zag_walk(std::vector<std::vector<T>> const &matrix)
{
	// How may diagonals have a matrix N x M?
	std::vector<T> diagonals;
	if (matrix.empty())
		return diagonals;

	std::size_t row_size = matrix.size() - 1;
	std::size_t col_size = matrix[0].size() - 1;

	diagonals.reserve(row_size * col_size);

	bool go_up = true;
	std::size_t row = 0;
	std::size_t col = 0;
	// We try to stay inside the boundary
	while (!check_bound(row_size, col_size, row, col)) {
		diagonals.push_back(matrix[row][col]);
		if (go_up) {
			go_up = walk_up(row_size, col_size, row, col);
		} else {
			go_up = walk_down(row_size, col_size, row, col);
		}
	}

	return diagonals;
}
