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

#include "../core/ReplyWorkers.hpp"
#include "TestTool.hpp"

using namespace std;

void TEST_CASE_ONE()
{
	std::string file = "resources/data_scenarios_a_example.in";
	auto lines = cpstl::tokenize_input_into_strings(file);
	std::vector<Building<long long>> buildings;
	std::vector<Antenna<long long>> antennas;
	cpstl::cp_log(LOG, lines[0]);
	auto tokens = cpstl::tokenize_string_by_simbol(lines[0], ' ');
	cpstl::cp_log(LOG, tokens[0] + " " + tokens[1]);
	auto x = tokens[0];
	auto y = tokens[1];
	cpstl::cp_log(LOG, "W=" + x + " H=" + y);

	tokens = cpstl::tokenize_string_by_simbol(lines[1], ' ');
	auto buildings_size = std::stoi(tokens[0]);
	auto antennas_size = std::stoi(tokens[1]);
	auto rewars = std::stoi(tokens[2]);

	buildings.reserve(buildings_size);
	auto indexLine = 2; // The first 2 are taken in the previous steps
	while (indexLine < buildings_size + 2) {
		tokens =
		    cpstl::tokenize_string_by_simbol(lines[indexLine], ' ');
		buildings.emplace_back(
		    std::stoi(tokens[0]), std::stoi(tokens[1]),
		    std::stoi(tokens[2]), std::stoi(tokens[3]));
		indexLine++;
	}

	assert(buildings_size == buildings.size());

	antennas.reserve(antennas_size);
	while (indexLine < antennas_size + 2 + buildings_size) {
		tokens =
		    cpstl::tokenize_string_by_simbol(lines[indexLine], ' ');
		antennas.emplace_back(std::stoi(tokens[0]),
				      std::stoi(tokens[1]));
		indexLine++;
	}

	auto result = solution<long long>(buildings, antennas, rewars);

	cpstl::assert_equal("TEST_CASE_ONE_SIZE_B", buildings_size,
			    (int)buildings.size());
	cpstl::assert_equal("TEST_CASE_ONE_SIZE_A", antennas_size,
			    (int)antennas.size());
}

int main()
{
	TEST_CASE_ONE();
	return EXIT_SUCCESS;
}
