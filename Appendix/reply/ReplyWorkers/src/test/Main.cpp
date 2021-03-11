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
#include "../core/ReplyWorkers.hpp"
#include "TestTool.hpp"
#include <cstdlib>

using namespace std;

void read_file_input(std::string &input_file);

void TEST_CASE_ONE()
{
	std::string file = "resources/a_solar.txt";
  OfficeFloor floor;
  std::vector<Developer<long>> developers;
  std::vector<Manager<long>> managers;

  auto lines = cpstl::tokenize_input_into_strings(file);

  auto line = lines[0];
  auto tokens = cpstl::tokenize_string_by_simbol(line, ' ');
  floor.width = std::stoi(tokens[0]);
  floor.height = std::stoi(tokens[1]);

  cpstl::assert_equal("TEST_CASE_ONE", "expected", "Actual");
}

int main()
{
	TEST_CASE_ONE();
	return EXIT_SUCCESS;
}
