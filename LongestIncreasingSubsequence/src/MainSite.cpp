
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
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename R>
R lis_dynamic_programming_with_mem(std::vector<T> const &input)
{
	std::vector<T> mem(input.size(), 1);
	for (std::size_t i = 0; i < input.size(); i++) {
		for (std::size_t j = 0; j < i; j++) {
			if (input[j] < input[i]) {
				mem[i] = std::max(mem[i], mem[j] + 1);
			}
		}
	}
	R lis = mem[0];
	for (std::size_t i = 0; i < input.size(); i++) {
		lis = std::max(lis, mem[i]);
	}
	return lis;
}

int main()
{
	int T;
	scanf("%d", &T);

	for (std::size_t t = 1; t <= T; t++) {
		int size;
		scanf("%d", &size);
		int buget;
		scanf("%d", &buget);
		vector<int> inputs;
		inputs.reserve(size);
		for (std::size_t i = 0; i < size; i++) {
			int value;
			scanf("%d", &value);
			inputs.push_back(value);
		}
		int result =
		    get_maximum_number_of_house<int, int>(inputs, buget);
		printf("Case #%lu: %d\n", t, result);
	}
}
