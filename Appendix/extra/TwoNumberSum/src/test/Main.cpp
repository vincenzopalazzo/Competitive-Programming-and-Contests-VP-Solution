/**
 * Segment tree data structure implementation
 * Copyright (C) 2020  Vincenzo Palazzo vincenzopalazzodev@gmail.com
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
#include <vector>
#include "TestTool.hpp"
#include "../core/TwoNumberSum.hpp"

using namespace std;

void TEST_CASE_ONE()
{
  vector<int> inputs = {3, 5, -4, 8, 11, 1, -1, 6};
  auto res = get_element_to_get_sum(inputs, 10);

  cpstl::assert_equal("TEST_CASE_ONE", {11, -1}, res);
}

void TEST_CASE_TWO()
{
  vector<int> inputs = {3, 5, -4, 8, 11, 1, -1, 6};
  auto res = get_element_to_get_sum_hasttb(inputs, 10);
  cpstl::assert_equal("TEST_CASE_TWO", {-1, 11}, res);
}

void TEST_CASE_THREE()
{
  vector<int> inputs = {3, 5, -4, 8, 11, 1, -1, 6};
  auto res = get_element_to_get_sum_two_pointer(inputs, 10);
  cpstl::assert_equal("TEST_CASE_THREE", {-1, 11}, res);
}

int main()
{
    TEST_CASE_ONE();
    TEST_CASE_TWO();
    TEST_CASE_THREE();
    return EXIT_SUCCESS;
}
