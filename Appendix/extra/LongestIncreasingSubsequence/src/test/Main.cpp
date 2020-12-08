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
#include "../core/LongestIncreasingSubsequence.h"

using namespace std;

static void TEST_CASE_ONE_DP()
{
    vector<int> map = {10,9,2,5,3,7,101,18};
    cpstl::cp_log(LOG, map);
    auto result = lis_dynamic_programming<int, int>(map);
    cpstl::assert_equal("TEST_CASE_ONE_DP", 4, result);
}

static void TEST_CASE_ONE_DP_MEM()
{
    vector<int> map = {10,9,2,5,3,7,101,18};
    cpstl::cp_log(LOG, map);
    auto result = lis_dynamic_programming_with_mem<int, int>(map);
    cpstl::assert_equal("TEST_CASE_ONE_DP_MEM", 4, result);
}

static void TEST_CASE_ONE_BIT()
{
    vector<int> map = {10, 9, 2, 5, 3, 7, 101, 18};
    cpstl::cp_log(LOG, map);
    auto result = lis_dynamic_programming_binary_index_tree<int, int>(map);
    cpstl::assert_equal("TEST_CASE_ONE_BIT", 4, result);
}

static void TEST_CASE_TWO_BIT()
{
    vector<int> map = {0, 1, 0, 3, 2, 3};
    cpstl::cp_log(LOG, map);
    auto result = lis_dynamic_programming_binary_index_tree<int, int>(map);
    cpstl::assert_equal("TEST_DEMO", 4, result);
}

static void TEST_CASE_THREE_BIT()
{
    vector<int> map = {7, 7, 7, 7, 7, 7, 7};
    cpstl::cp_log(LOG, map);
    auto result = lis_dynamic_programming_binary_index_tree<int, int>(map);
    cpstl::assert_equal("TEST_CASE_THREE_BIT", 1, result);
}

static void TEST_CASE_FOUR_BIT()
{
    vector<int> map = {4, 10, 4, 3, 8, 9};
    cpstl::cp_log(LOG, map);
    auto result = lis_dynamic_programming_binary_index_tree<int, int>(map);
    cpstl::assert_equal("TEST_CASE_FOUR_BIT", 3, result);
}

int main()
{
    TEST_CASE_ONE_DP();
    TEST_CASE_ONE_DP_MEM();
    TEST_CASE_ONE_BIT();
    TEST_CASE_TWO_BIT();
    TEST_CASE_THREE_BIT();
    TEST_CASE_FOUR_BIT();
    return EXIT_SUCCESS;
}