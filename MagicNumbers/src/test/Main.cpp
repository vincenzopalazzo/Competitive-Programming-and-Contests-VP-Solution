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
#include "TestTool.hpp"
#include "../core/MagicNumbers.hpp"

using namespace std;

void TEST_CASE_ONE()
{
    auto input = "114114";
    auto result = is_magic_number(input);
    cpstl::assert_is_true("TEST_CASE_ONE",  result);
}

void TEST_CASE_TWO()
{
    auto input = "1111";
    auto result = is_magic_number(input);
    cpstl::assert_is_true("TEST_CASE_TWO", result);
}

void TEST_CASE_THREE()
{
    auto input = "441231";
    auto result = is_magic_number(input);
    cpstl::assert_is_true("TEST_CASE_THREE", !result);
}

int main()
{
    TEST_CASE_ONE();
    TEST_CASE_TWO();
    TEST_CASE_THREE();
    return EXIT_SUCCESS;
}