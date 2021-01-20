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
#include <iostream>
#include <vector>

using namespace std;

namespace cpstl
{
/**
 * Segment tree data structure implementation
 * Copyright (C) 2020  Vincenzo Palazzo vincenzopalazzodev@gmail.com
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
template <class T, typename R> class SegmentTree
{
      private:
	std::vector<T> &origin;
	std::vector<R> structure;

	/**
	 * This function is used build the segment tree with a binary heap
	 * implementation, and it use the origin array stored in the class.
	 * @tparam T is the type of structure, usually it is a int or another
	 * numeric type
	 * @param left_index the left index of the range
	 * @param right_index the right index of the range
	 */
	void build_structure(int left_index, int right_index)
	{
		build_structure_procedure(1, left_index, right_index - 1);
	}

	/**
	 * This is the sub procedure that help the build_structure procedure to
	 * make the logic inside the segment tree
	 * @tparam T is the type of structure, usually it is a int or another
	 * numeric type
	 * @param start_index
	 * @param left_index
	 * @param right_index
	 */
	void build_structure_procedure(std::size_t start_index,
				       std::size_t left_index,
				       std::size_t right_index)
	{
		if (left_index == right_index) {
			if (origin[left_index] == 0)
				structure[start_index] = 1;
			else
				structure[start_index] = 0;
			return;
		}
		auto middle_point = (left_index + right_index) / 2;
		auto left_child = left_child_index(start_index);
		auto right_child = right_child_index(start_index);
		build_structure_procedure(left_child, left_index, middle_point);
		build_structure_procedure(right_child, middle_point + 1,
					  right_index);
		// Internal node will have the sum of both of its children
		auto segment_left = structure[left_child];
		auto segment_right = structure[right_child];
		structure[start_index] = segment_left + segment_right;
	}

	R range_query_subroutine(std::size_t start_index,
				 std::size_t left_index_now,
				 std::size_t right_index_now, T k)
	{
		if (structure[start_index] < k)
			return -1;
		if (left_index_now == right_index_now)
			return left_index_now; // range represented by a node is
					       // completely inside the given
					       // range
		// range represented by a node is partially inside and partially
		// outside the given range
		auto middle_point = (left_index_now + right_index_now) / 2;
		auto left_child = left_child_index(start_index);
		auto right_child = right_child_index(start_index);
		if (structure[left_child] >= k)
			return range_query_subroutine(
			    left_child, left_index_now, middle_point, k);
		return range_query_subroutine(right_child, middle_point + 1,
					      right_index_now,
					      k - structure[left_child]);
	}

	void update_subroutine(std::size_t start_index, std::size_t left_index,
			       std::size_t right_index, std::size_t pos,
			       T new_value)
	{
		if (left_index == right_index) {
			origin[pos] = new_value;
			if (origin[pos] == 0)
				structure[start_index] = 1;
			else
				structure[start_index] = 0;
		} else {
			auto middle_point = (left_index + right_index) / 2;
			auto left_child = left_child_index(start_index);
			auto right_child = right_child_index(start_index);
			if (pos <= middle_point) {
				update_subroutine(left_child, left_index,
						  middle_point, pos, new_value);
			} else {
				update_subroutine(right_child, middle_point + 1,
						  right_index, pos, new_value);
			}
			auto segment_left = structure[left_child];
			auto segment_right = structure[right_child];
			structure[start_index] = segment_left + segment_right;
		}
	}

	inline std::size_t left_child_index(const std::size_t index)
	{
		return index * 2;
	}

	inline std::size_t right_child_index(const std::size_t index)
	{
		return (index * 2) + 1;
	}

      public:
	SegmentTree(std::vector<T> &origin) : origin(origin)
	{
		std::size_t size = origin.size();
		structure = std::vector<T>(size * 4);
		origin = origin;
		build_structure(0, size);
	}

	virtual ~SegmentTree() { structure.clear(); }

	R range_query(T key)
	{
		return range_query_subroutine(1, 0, origin.size() - 1, key);
	}

	/**
	 * This is the sub procedure that help the build_structure procedure to
	 * make the logic inside the segment tree
	 * @param at: it is the position in the original array, the function
	 * change the value also in the original array
	 * @param new_value the value that we want override in position at.
	 */
	void update(std::size_t at, T value)
	{
		update_subroutine(1, 0, origin.size() - 1, at, value);
	}
};
}; // namespace cpstl

template <typename T> struct Query {
	T value;
	std::size_t at;
	bool update;

	Query(T value) : value(value)
	{
		update = false;
		at = -1;
	}

	Query(T value, size_t at) : value(value), at(at) { update = true; }
};

template <typename T, typename R>
static std::vector<R> find_number_of_zeros(std::vector<T> &inputs,
					   std::vector<Query<T>> const &queries)
{
	auto segment_tree = cpstl::SegmentTree<T, R>(inputs);
	vector<R> results;
	results.reserve(queries.size());
	for (auto query : queries) {
		if (query.update) {
			segment_tree.update(query.at, query.value);
		} else {
			auto result = segment_tree.range_query(query.value);
			results.push_back(result);
		}
	}
	return results;
}

int main()
{
	int N, Q;
	scanf("%d", &N);
	scanf("%d", &Q);

	std::vector<int> inputs;
	inputs.reserve(N);
	// Read the array
	for (std::size_t t = 0; t < N; t++) {
		int value;
		scanf("%d", &value);
		inputs.push_back(value);
	}
	std::vector<Query<int>> queries;
	queries.reserve(Q);
	for (int i = 0; i < Q; i++) {
		int type, k, pos, val;
		scanf("%d", &type);
		if (type == 1) {
			scanf("%d", &k);
			queries.emplace_back(k);
		} else {
			scanf("%d%d", &pos, &val);
			queries.emplace_back(val, pos);
		}
	}
	auto result = find_number_of_zeros<int, int>(inputs, queries);
	for (auto ans : result) {
		if (ans == -1)
			printf("NO\n");
		else
			printf("%d\n", ans);
	}
	return EXIT_SUCCESS;
}
