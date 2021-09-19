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
static bool can_place_naive(std::vector<std::vector<T>> const &board,
                            std::size_t x, std::size_t y) {

  std::size_t row_size = board.size();
  std::size_t col_size = row_size > 0 ? board[0].size() : 0;
  // I take the row and see for each colum if there is somethings
  // with one, if yes, this it node the correct place to add a queen.
  for (std::size_t col_i = 0; col_i < board[x].size(); col_i++) {
    if (board[x][col_i])
      return false;
  }

  // Same things for the row, I iterate from all the row
  // and check if in the same colum there is a one.
  for (auto const &row : board) {
    if (row[y])
      return false;
  }

  // TODO check the diagonal, I can not place a queen in the same diagonal

  for (std::size_t i = 0; i < row_size + col_size - 1; i++) {
    // TODO check for the diagonal
  }

  return true;
}

template <typename T>
static std::vector<std::vector<T>> solution_complete_search_naive(std::size_t x_pos, std::size_t y_pos, std::size_t size_row = 8) {

  auto board = std::vector<std::vector<T>>(size_row, std::vector<T>(size_row, 0));
  // The board it is index by 1
  board[x_pos - 1][y_pos - 1] = true;

  for (std::size_t row_index = 0; row_index < board.size(); row_index++)
    for (std::size_t col_index = 0;
         col_index < board[row_index].size(); col_index++) {
      if (can_place_naive(board, row_index, col_index)) {
        board[row_index][col_index] = true;
      }
    }

  return board;
}

/**
 * This contains one optimization included in the book competitive programming.
 * The tips here is that the two queen can node share the same colum or the same
 * row.
 */
template <typename T>
static std::vector<T> solution_complete_search_tips_one(std::size_t start_x, std::size_t start_y, std::size_t size_row = 8)
{
  std::vector<T> row(size_row, 0);



  return row;
}
