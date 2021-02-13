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
#include <string>
#include <vector>

template <typename T> 
T trapping_water_one_sol(const std::vector<T> &inputs)
{
	if (inputs.empty())
		return 0;
	T water = 0;
	for (int i = 1; i < inputs.size() - 1; i++) {

		T left_max = inputs.at(i);
		for (int j = 0; j < i; j++) {
			left_max = std::max(left_max, inputs.at(j));
		}

		T right_max = inputs.at(i);
		for (int j = i + 1; j < inputs.size(); j++) {
			right_max = std::max(right_max, inputs.at(j));
		}

		water += std::min(left_max, right_max) - inputs.at(i);
	}

	return water;
}

template <typename T>
T trapping_water_optimize_sol(const std::vector<T> &inputs)
{
	// With some judge wee need this line of code!
	// e.g: https://leetcode.com/
	// if (inputs.empty()) return 0;
	T right_max_values[inputs.size()];
	T left_max_values[inputs.size()];
	T water = 0;

	left_max_values[0] = inputs.at(0);
	for (int i = 1; i < inputs.size(); i++) {
		left_max_values[i] = std::max(left_max_values[i - 1], inputs.at(i));
	}

	right_max_values[inputs.size() - 1] = inputs.at(inputs.size() - 1);
	for (int i = inputs.size() - 2; i >= 0; i--) {
		right_max_values[i] =
		    std::max(right_max_values[i + i], inputs.at(i));
	}

	for (int i = 0; i < inputs.size(); i++) {
		water +=
		    std::min(left_max_values[i], right_max_values[i]) - inputs.at(i);
	}
	return water;
}