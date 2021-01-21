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
#include "../test/Utils.hpp"
#include <cstdlib>
#include <string>
#include <vector>

const cpstl::Log LOG(false);

template <typename R>
static R get_max_from_vectors(std::vector<R> const &vector_one,
			      std::vector<R> const &vector_two) {
	R max = 0;
	for (std::size_t i = 0; i < vector_one.size(); i++) {
		auto elem_one = vector_one[i];
		auto elem_two = vector_two[i];
		if (max < (elem_one + elem_two)) {
			max = elem_one + elem_two - 1;
		}
	}
	return max;
}

template <typename T, typename R>
static R find_size_bitonic_subsequence(std::vector<T> const &inputs)
{
	std::vector<R> increasing_subs(inputs.size(), 1);
	std::vector<T> incresing_sub_rev(inputs.size(), 1);
	for (std::size_t i = 0; i < inputs.size(); i++) {
		for (std::size_t j = 0; j < i; j++) {
			if (inputs[i] > inputs[j]) {
				auto elem_one = increasing_subs[i];
				auto elem_two = increasing_subs[j] + 1;
				increasing_subs[i] =
				    std::max(elem_one, elem_two);
			}
		}
	}
	for (int i = inputs.size() - 2; i >= 0; i--) {
		for (int j = inputs.size() - 1; j > i; j--) {
			if (inputs[i] > inputs[j]) {
				auto elem_one = incresing_sub_rev[i];
				auto elem_two = incresing_sub_rev[j] + 1;
				incresing_sub_rev[i] =
				    std::max(elem_one, elem_two);
			}
		}
	}
	return get_max_from_vectors(increasing_subs, incresing_sub_rev);
}
