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
#include "../core/FibonacciNum.h"

using namespace std;

void TEST_CASE_ONE_NAIVE()
{
    auto res = fibonacci_num(44);
    cpstl::assert_equal("TEST_CASE_ONE_NAIVE", 701408733, res);
}

void TEST_CASE_ONE_MEM()
{
    auto res = fibonacci_num_mem(44);
    cpstl::assert_equal("TEST_CASE_ONE_MEM", 701408733, res);
}

void TEST_CASE_ONE_TAB()
{
    auto res = fibonacci_num_tab(44);
    cpstl::assert_equal("TEST_CASE_ONE_TAB", 701408733, res);
}

int main()
{
    TEST_CASE_ONE_NAIVE();
    TEST_CASE_ONE_MEM();
    TEST_CASE_ONE_TAB();
    return EXIT_SUCCESS;
}