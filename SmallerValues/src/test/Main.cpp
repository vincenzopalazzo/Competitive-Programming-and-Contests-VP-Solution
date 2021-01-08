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
#include "../core/SmallerValues.hpp"

using namespace std;

void TEST_CASE_ONE_SEGMENT_TREE()
{
    std::vector<int> inputs = {4, 1, 3, 4, 1 };
    std::vector<Query<int>> queries;
    queries.emplace_back(0, 1, 3);
    queries.emplace_back(0, 4, 3);
    queries.emplace_back(1, 3, 2);
    auto result = smaller_value_segment_tree<int, int>(inputs, queries);
    cpstl::assert_equal("TEST_CASE_ONE_SEGMENT_TREE", {1, 3, 1}, result);
}

void TEST_CASE_TEST_CASE_ZERO_SEGMENT_TREE()
{
    std::string input_file = "/home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/SmallerValues/src/test/files/input0.txt";
    std::string output_file = "/home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/SmallerValues/src/test/files/output0.txt";

    auto inputs = cpstl::load_sequences_from_file<int>(input_file);
    auto queries = cpstl::load_query_from_file<Query<int>>(input_file);
    auto expected_result = cpstl::load_result_from_file<int>(output_file);

    auto result = smaller_value_segment_tree<int, int>(inputs, queries);

    cpstl::assert_equal("TEST_CASE_TEST_CASE_ONE_SEGMENT_TREE", expected_result, result);
}

void TEST_CASE_TEST_CASE_ONE_SEGMENT_TREE()
{
    std::string input_file = "/home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/SmallerValues/src/test/files/input1.txt";
    std::string output_file = "/home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/SmallerValues/src/test/files/output1.txt";
    std::vector<int> inputs = cpstl::load_sequences_from_file<int>(input_file);
    std::vector<Query<int>> queries = cpstl::load_query_from_file<Query<int>>(input_file);
    auto result = smaller_value_segment_tree<int, int>(inputs, queries);
    auto expected_result = cpstl::load_result_from_file<int>(output_file);
    cpstl::assert_equal("TEST_CASE_TEST_CASE_ONE_SEGMENT_TREE", expected_result, result);
}

void TEST_CASE_TEST_UNIT_SEGMENT_TREE()
{
    int battery_test = 8;
    std::string input_file = "/home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/SmallerValues/src/test/files/input";
    std::string output_file = "/home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/SmallerValues/src/test/files/output";
    std::string exstension = ".txt";
    for (int i = 0; i <= battery_test; i++) {
        std::vector<int> inputs = cpstl::load_sequences_from_file<int>(input_file + std::to_string(i) + exstension);
        std::vector<Query<int>> queries = cpstl::load_query_from_file<Query<int>>(input_file + std::to_string(i) + exstension);
        auto result = smaller_value_segment_tree<int, int>(inputs, queries);
        auto expected_result = cpstl::load_result_from_file<int>(output_file + std::to_string(i) + exstension);
        cpstl::assert_equal("TEST_CASE_TEST_UNIT_SEGMENT_TREE -> " + std::to_string(i + 1) +  "th", expected_result, result);
    }
}

int main()
{
    TEST_CASE_ONE_SEGMENT_TREE();
    TEST_CASE_TEST_CASE_ZERO_SEGMENT_TREE();
    TEST_CASE_TEST_CASE_ONE_SEGMENT_TREE();
    TEST_CASE_TEST_UNIT_SEGMENT_TREE();
    return EXIT_SUCCESS;
}