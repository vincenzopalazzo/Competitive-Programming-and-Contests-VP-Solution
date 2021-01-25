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
#include <map>
#include <vector>
#include <cassert>
#include "../test/Utils.hpp"
#include "PersistentSegmentTree.hpp"

const cpstl::Log LOG(true);

template <typename T>
struct Query {
  T target;
  std::size_t start;
  std::size_t end;

  Query(std::size_t start, std::size_t end, T target)
      : start(start), end(end), target(target) {}
};

// Look bettere the remapping operation
//https://github.com/anudeep2011/programming/blob/master/MKTHNUM.cpp#L29
template <typename T>
static std::vector<T> remapping_original_array(std::vector<std::pair<T, std::size_t>> &inputs)
{
	std::sort(inputs.begin(), inputs.end());
	auto index = 1;
	std::vector<T> remapping(inputs.size());
	for (auto elem : inputs) {
		remapping[elem.second] = index;
		index++;
	}
	return remapping;
}

template <typename T, typename R>
static std::vector<T> get_smaller_number_persistent_segtree(std::vector<std::pair<T, std::size_t>> &inputs,
																														std::vector<Query<T>> const &queries) {
	auto remapping = remapping_original_array(inputs);

	auto segment_tree = cpstl::PersistentSegmentTree<T>(1, remapping.size());

	for (auto elem : remapping) {
		segment_tree.update(elem, 1);
	}

	std::vector<T> result_vector;
	result_vector.reserve(queries.size());
	for (auto query : queries) {
		auto result = segment_tree.range_query(query.start - 1, query.end, query.target);
		std::cout << result << "\n";
		result_vector.push_back(inputs[result - 1].first);
	}
	return result_vector;
}

template <typename T>
static T get_smaller_number_naive(std::vector<T> &inputs,
																	std::vector<Query<T>> const &queries) {
  return inputs[0];
}
