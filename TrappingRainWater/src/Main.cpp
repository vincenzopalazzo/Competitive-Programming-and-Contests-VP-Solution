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
#include "core/TrappingRainWater.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	std::vector<int> inputs = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	std::cout << "Water trapped: " << trapping_water_one_sol(inputs)
		  << "\n";

	inputs = {7, 4, 0, 9};
	std::cout << "Water trapped: " << trapping_water_one_sol(inputs)
		  << "\n";

	// 8 8 2 4 5 5 1
	inputs = {8, 8, 2, 4, 5, 5, 1};
	std::cout << "Water trapped: " << trapping_water_one_sol(inputs)
		  << "\n";

	std::cout << "--------------- OPTIMIZZED ---------------------\n";
	inputs = {7, 4, 0, 9};
	std::cout << "Water trapped: " << trapping_water_optimize_sol(inputs)
		  << "\n";

	// 8 8 2 4 5 5 1
	inputs = {8, 8, 2, 4, 5, 5, 1};
	std::cout << "Water trapped: " << trapping_water_optimize_sol(inputs)
		  << "\n";

	// 1 1 5 2 7 6 1 4 2 3
	inputs = {1, 1, 5, 2, 7, 6, 1, 4, 2, 3};
	std::cout << "Water trapped: " << trapping_water_optimize_sol(inputs)
		  << "\n";
	return EXIT_SUCCESS;
}
