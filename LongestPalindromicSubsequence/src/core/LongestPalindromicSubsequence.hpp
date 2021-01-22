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
#include "../test/Utils.hpp"

const cpstl::Log LOG(true);

template <typename T>
static T recursion_find_longest_subsequence(std::string const &sequence,
					    std::size_t start, std::size_t end)
{
	if (start == end)
		return 1; // One character is equal to itself. subsequence lenght 1
	if (sequence[start] == sequence[end] && start + 1 == end)
		return 2; // Only two character and it are the same.

	if (sequence[start] == sequence[end])
		return recursion_find_longest_subsequence<T>(sequence, start + 1, end -1) + 2;

	auto take_left = recursion_find_longest_subsequence<T>(sequence, start + 1, end);
	auto take_right = recursion_find_longest_subsequence<T>(sequence, start, end - 1);
	return std::max(take_left, take_right);
}

template <typename T>
static T longest_palindromic_subsequence(std::string const &sequence)
{
	return recursion_find_longest_subsequence<T>(sequence, 0, sequence.length());
}


template <typename T>
static T longest_palindromic_subsequence_mem(std::string const & sequences)
{
	if (sequences.empty()) return 0;

	std::vector<T> memorizzation(sequences.length());

	for(int i = sequences.length() - 1; i >= 0; i--)
        {
		auto last_choosen = 0;
		for(int j = i; j < sequences.length(); j++) {
			if (i == j) {
				memorizzation[j] = 1;
			} else if (sequences[i] == sequences[j]) {
				auto tmp = memorizzation[j];
				memorizzation[j] = last_choosen + 2;
				last_choosen = tmp;
			} else {
				auto left = memorizzation[j - 1];
				auto right = memorizzation[j];
				last_choosen = memorizzation[j];
				memorizzation[j] = std::max(left, right);
			}

		}
	}

	return memorizzation[sequences.length() - 1];
}
