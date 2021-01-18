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
#include "../core/MinimumNumberOfJumps.hpp"

using namespace std;

void TEST_CASE_ONE()
{
	std::vector<int> inputs = {};
	auto result = minimize_jump_to_reach_end(inputs);
	cpstl::assert_equal("TEST_CASE_ONE", 0, result);
}

void TEST_CASE_TWO()
{
	std::vector<int> inputs = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	auto result = minimize_jump_to_reach_end(inputs);
	cpstl::assert_equal("TEST_CASE_TWO", 3, result);
}

void TEST_CASE_THREE()
{
	std::vector<int> inputs = {1, 4, 3, 2, 6, 7};
	auto result = minimize_jump_to_reach_end(inputs);
	cpstl::assert_equal("TEST_CASE_THREE", 2, result);
}

void TEST_CASE_FOUR()
{
	std::vector<int> inputs = {0, 1};
	auto result = minimize_jump_to_reach_end(inputs);
	cpstl::assert_equal("TEST_CASE_FOUR", -1, result);
}

void TEST_CASE_ONE_OPTIMIZZATION()
{
	std::vector<int> inputs = {};
	auto result = optimize_minimum_jump_to_reach_end(inputs);
	cpstl::assert_equal("TEST_CASE_ONE_OPTIMIZZATION", 0, result);
}

void TEST_CASE_TWO_OPTIMIZZATION()
{
	std::vector<int> inputs = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	auto result = optimize_minimum_jump_to_reach_end(inputs);
	cpstl::assert_equal("TEST_CASE_THREE_OPTIMIZZATION", 3, result);
}

void TEST_CASE_THREE_OPTIMIZZATION()
{
	std::vector<int> inputs = {1, 4, 3, 2, 6, 7};
	auto result = optimize_minimum_jump_to_reach_end(inputs);
	cpstl::assert_equal("TEST_CASE_THREE_OPTIMIZZATION", 2, result);
}

int main()
{
	TEST_CASE_ONE();
	TEST_CASE_TWO();
	TEST_CASE_THREE();
	TEST_CASE_FOUR();
	TEST_CASE_ONE_OPTIMIZZATION();
	TEST_CASE_TWO_OPTIMIZZATION();
	TEST_CASE_THREE_OPTIMIZZATION();
	return EXIT_SUCCESS;
}
