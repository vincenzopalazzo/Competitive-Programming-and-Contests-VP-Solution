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
#include <cstdlib>

#include "../core/MKthNum.hpp"
#include "TestTool.hpp"

using namespace std;

void TEST_CASE_ONE_PERSISTENT() {
  std::vector<std::pair<int, std::size_t>> inputs = {
      {1, 0}, {5, 1}, {2, 2}, {6, 3}, {3, 4}, {7, 5}, {4, 6}};
  std::vector<Query<int>> queries;
  queries.emplace_back(2, 5, 3);
  queries.emplace_back(4, 4, 1);
  queries.emplace_back(1, 7, 3);
  auto result = get_kth_number_persistent_segtree<int>(inputs, queries);
  cpstl::assert_equal("TEST_CASE_ONE_PERSISTENT", {5, 6, 3}, result);
}

void TEST_CASE_ONE_CUSTOM_SEGMENT_TREE() {
  std::vector<int> inputs = {1, 5, 2, 6, 3, 7, 4};
  std::vector<Query<int>> queries;
  queries.emplace_back(2, 5, 3);
  queries.emplace_back(4, 4, 1);
  queries.emplace_back(1, 7, 3);
  auto result = get_kth_number_segment_tree<int>(inputs, queries);
  cpstl::assert_equal("TEST_CASE_ONE_CUSTOM_SEGMENT_TREE", {5, 6, 3}, result);
}

void TEST_CASE_ONE_CUSTOM_SEGMENT_TREE_OPT() {
  std::vector<int> inputs = {1, 5, 2, 6, 3, 7, 4};
  std::vector<Query<int>> queries;
  queries.emplace_back(2, 5, 3);
  queries.emplace_back(4, 4, 1);
  queries.emplace_back(1, 7, 3);
  auto result = get_kth_number_segment_tree_optimization<int>(inputs, queries);
  cpstl::assert_equal("TEST_CASE_ONE_CUSTOM_SEGMENT_TREE_OPT", {5, 6, 3},
                      result);
}

int main() {
  TEST_CASE_ONE_PERSISTENT();
  TEST_CASE_ONE_CUSTOM_SEGMENT_TREE();
  TEST_CASE_ONE_CUSTOM_SEGMENT_TREE_OPT();
  return EXIT_SUCCESS;
}
