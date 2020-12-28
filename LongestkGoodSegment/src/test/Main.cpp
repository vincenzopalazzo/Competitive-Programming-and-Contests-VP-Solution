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
#include "../core/LongestkGoodSegment.h"
#include "Utils.hpp"

const cpstl::Log LOG(false);

using namespace std;

void TEST_CASE_ONE_TWO_POINTER()
{
    vector<int> inputs = {1, 2, 3, 4, 5};
    cpstl::cp_log(LOG, inputs);
    auto index = calculate_kgood_segment_two_pointer(inputs, 5);
    vector<std::size_t> result = {index.first, index.second};
    cpstl::assert_equal("TEST_CASE_ONE_TWO_POINTER", {1, 5}, result);
}

void TEST_CASE_ONE_TWO_POINTER_QUEUE()
{
    vector<int> inputs = {1, 2, 3, 4, 5};
    cpstl::cp_log(LOG, inputs);
    auto index = calculate_kgood_segment_two_pointer_queue(inputs, 5);
    vector<std::size_t> result = {index.first, index.second};
    cpstl::assert_equal("TEST_CASE_ONE_TWO_POINTER_QUEUE", {1, 5}, result);
}

void TEST_CASE_TWO_TWO_POINTER()
{
    vector<int> inputs = {6, 5, 1, 2, 3, 2, 1, 4, 5};
    cpstl::cp_log(LOG, inputs);
    auto index = calculate_kgood_segment_two_pointer(inputs, 3);
    vector<std::size_t> result = {index.first, index.second};
    cpstl::assert_equal("TEST_CASE_TWO_TWO_POINTER", {3, 7}, result);
}

void TEST_CASE_TWO_TWO_POINTER_QUEUE()
{
    vector<int> inputs = {6, 5, 1, 2, 3, 2, 1, 4, 5};
    cpstl::cp_log(LOG, inputs);
    auto index = calculate_kgood_segment_two_pointer_queue(inputs, 3);
    vector<std::size_t> result = {index.first, index.second};
    cpstl::assert_equal("TEST_CASE_TWO_TWO_POINTER_QUEUE", {3, 7}, result);
}

void TEST_CASE_THREE_TWO_POINTER()
{
    vector<int> inputs = {1, 2, 3};
    cpstl::cp_log(LOG, inputs);
    auto index = calculate_kgood_segment_two_pointer(inputs, 1);
    vector<std::size_t> result = {index.first, index.second};
    cpstl::assert_equal("TEST_CASE_THREE_TWO_POINTER", {1, 1}, result);
}

void TEST_CASE_THREE_TWO_POINTER_QUEUE()
{
    vector<int> inputs = {1, 2, 3};
    cpstl::cp_log(LOG, inputs);
    auto index = calculate_kgood_segment_two_pointer_queue(inputs, 1);
    vector<std::size_t> result = {index.first, index.second};
    cpstl::assert_equal("TEST_CASE_THREE_TWO_POINTER_QUEUE", {1, 1}, result);
}

int main()
{
    cout << setprecision(10) << fixed;
    TEST_CASE_ONE_TWO_POINTER();
    TEST_CASE_ONE_TWO_POINTER_QUEUE();
    TEST_CASE_TWO_TWO_POINTER();
    TEST_CASE_TWO_TWO_POINTER_QUEUE();
    TEST_CASE_THREE_TWO_POINTER();
    TEST_CASE_THREE_TWO_POINTER_QUEUE();
    return EXIT_SUCCESS;
}