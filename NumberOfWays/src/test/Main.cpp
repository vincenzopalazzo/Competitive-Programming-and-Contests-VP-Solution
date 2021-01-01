/**
 * Copyright (C) 2020  Vincenzo Palazzo vincenzopalazzodev@gmail.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include <cstdlib>
#include <vector>
#include "TestTool.hpp"
#include "../core/NumberOfWays.hpp"

using namespace std;

void TEST_CASE_ONE()
{
  vector<int> inputs = {1, 2, 3, 0, 3};
  auto res = count_numbers_of_ways_prefix_sum<int, int>(inputs);

  cpstl::assert_equal("TEST_CASE_ONE", 2, res);
}

void TEST_CASE_TWO()
{
  vector<int> inputs = {0, 1, -1, 0};
  auto res = count_numbers_of_ways_prefix_sum<int, int>(inputs);

  cpstl::assert_equal("TEST_CASE_TWO", 1, res);
}

void TEST_CASE_THREE()
{
  vector<int> inputs = {4, 1};
  auto res = count_numbers_of_ways_prefix_sum<int, int>(inputs);
  cpstl::assert_equal("TEST_CASE_THREE", 0, res);
}

int main()
{
    TEST_CASE_ONE();
    TEST_CASE_TWO();
    TEST_CASE_THREE();
    return EXIT_SUCCESS;
}
