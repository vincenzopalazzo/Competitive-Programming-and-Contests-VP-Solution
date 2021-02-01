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

#include "../core/RangeUpdatesSums.hpp"
#include "TestTool.hpp"

using namespace std;

template <typename T>
static std::vector<Query<T>> load_query_from_file(std::string const &name_file);

void TEST_CASE_ONE() {
  std::vector<int> input = {2, 3, 1, 1, 5, 3};
  std::vector<Query<int>> queries;
  queries.emplace_back(3, 5);
  queries.emplace_back(2, 2, 4, 1);
  queries.emplace_back(3, 5);
  queries.emplace_back(5, 2, 4, 2);
  queries.emplace_back(3, 5);
  auto result = range_sum_lazy_segment_tree<int, int>(input, queries);
  cpstl::assert_equal("TEST_CASE_ONE", {7, 11, 15}, result);
}

void TEST_CASE_TWO() {
  std::vector<int> inputs;
  std::vector<Query<int>> queries;
  std::string const name_file =
      "/home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/"
      "Appendix/report_experiment/RangeUpdatesSums/src/test/resources/"
      "input1.txt";
  std::string const name_file_result = "/home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/Appendix/report_experiment/RangeUpdatesSums/src/test/resources/result1.txt";
  inputs = cpstl::load_input_from_file<int>(name_file);
  queries = load_query_from_file<int>(name_file);
  auto expected = cpstl::load_results_from_file<int>(name_file_result);
  auto result = range_sum_lazy_segment_tree<int, int>(inputs, queries);
  cpstl::assert_equal("TEST_CASE_TWO", expected, result);
}

int main() {
  TEST_CASE_ONE();
  TEST_CASE_TWO();
  return EXIT_SUCCESS;
}


template<typename T>
static std::vector<Query<T>> load_query_from_file(std::string const &file_name) {
  std::ifstream input_file(file_name);
  assert(input_file.is_open());

  std::vector<Query<T>> queries;

  while (!input_file.eof()) {
    std::size_t N, Q;
    input_file >> N;
    input_file >> Q;
    for (std::size_t i = 0; i < N; i++) {
      T value;
      input_file >> value;
    }

    for (std::size_t i = 0; i < Q; i++) {
      uint type;
      std::size_t start, end;
      input_file >> type;
      input_file >> start >> end;
      if(type != 3) {
        T value;
        input_file >> value;
        queries.emplace_back(value, start, end, type);
      } else {
        queries.emplace_back(start, end);
      }
    }
    return queries;
  }
  assert(false && "This should never happen");
  return queries;
}
