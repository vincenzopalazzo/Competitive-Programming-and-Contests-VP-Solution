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
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace cpstl {
    /**
    * Segment tree data structure implementation
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
    template<class T>
    class SegmentTree {
    private:
        std::vector<T> &origin;
        std::vector<T> structure;

        /**
         * This function is used build the segment tree with a binary heap
         * implementation, and it use the origin array stored in the class.
         * @tparam T is the type of structure, usually it is a int or another numeric type
         * @param left_index the left index of the range
         * @param right_index the right index of the range
         */
        void build_structure(std::size_t left_index, std::size_t right_index) {
            build_structure_procedure(1, left_index, right_index - 1);
        }

        /**
         * This is the sub procedure that help the build_structure procedure to make the logic inside the segment tree
         * @tparam T is the type of structure, usually it is a int or another numeric type
         * @param start_index
         * @param left_index
         * @param right_index
         */
        void build_structure_procedure(std::size_t start_index, std::size_t left_index, std::size_t right_index) {
            if (left_index == right_index) {
                // Leaf node will have a single element
                structure[start_index] = left_index;
                return;
            }
            std::size_t middle_point = (left_index + right_index) / 2;
            std::size_t left_child = left_child_index(start_index);
            std::size_t right_child = right_child_index(start_index);
            build_structure_procedure(left_child, left_index, middle_point);
            build_structure_procedure(right_child, middle_point + 1, right_index);
            // Internal node will have the sum of both of its children
            std::size_t segment_left = structure[left_child];
            std::size_t segment_right = structure[right_child];
            structure[start_index] = (origin[segment_left] <= origin[segment_right]) ? segment_left : segment_right;
        }

        int range_query_subroutine(std::size_t start_index, std::size_t left_index_now, std::size_t right_index_now,
                                   std::size_t query_left, std::size_t query_right) {
            if (query_left > right_index_now || query_right < left_index_now) return -1; // outside the range
            if (left_index_now >= query_left && right_index_now <= query_right)
                return structure[start_index]; // range represented by a node is completely inside the given range
            // range represented by a node is partially inside and partially outside the given range
            std::size_t middle_point = (left_index_now + right_index_now) / 2;
            std::size_t left_child = left_child_index(start_index);
            std::size_t right_child = right_child_index(start_index);
            std::size_t left_segment = range_query_subroutine(left_child, left_index_now, middle_point,
                                                              query_left, query_right);
            std::size_t right_segment = range_query_subroutine(right_child, middle_point + 1, right_index_now,
                                                               query_left, query_right);
            if (left_segment == -1) return right_segment;
            if (right_segment == -1) return left_segment;
            return (origin[left_segment] <= origin[right_segment]) ? left_segment : right_segment;
        }

        void
        update_subroutine(std::size_t start_index, std::size_t left_index, std::size_t right_index, std::size_t pos,
                          T new_value) {
            if (left_index == right_index) {
                origin[pos] = new_value;
                structure[start_index] = pos;
                return;
            }
            size_t middle_point = (left_index + right_index) / 2;
            size_t left_child = left_child_index(start_index);
            size_t right_child = right_child_index(start_index);
            if (pos <= middle_point) {
                update_subroutine(left_child, left_index, middle_point, pos, new_value);
            } else {
                update_subroutine(right_child, middle_point + 1, right_index, pos, new_value);
            }
            size_t segment_left = structure[left_child];
            size_t segment_right = structure[right_child];
            structure[start_index] = (origin[segment_left] <= origin[segment_right]) ? segment_left : segment_right;
        }

        inline int left_child_index(const std::size_t index) {
            //return index << 1;
            return index * 2;
        }

        inline int right_child_index(const std::size_t index) {
            //return (index << 1) + 1;
            return (index * 2) + 1;
        }

    public:

        SegmentTree(std::vector<T> &origin) : origin(origin) {
            std::size_t size = origin.size();
            structure = std::vector<T>(size * 4);
            origin = origin;
            build_structure(0, size);
        }

        virtual ~SegmentTree() {
            structure.clear();
        }

        int range_query(std::size_t start_index, std::size_t end_index) {
            return range_query_subroutine(1, 0, origin.size() - 1, start_index, end_index);
        }

        /**
         * This is the sub procedure that help the build_structure procedure to make the logic inside the segment tree
         * @param at: it is the position in the original array, the function change the value also in the original array
         * @param new_value the value that we want override in position at.
         */
        void update(std::size_t at, T value) {
            update_subroutine(1, 0, origin.size() - 1, at, value);
        }

        inline int left_child(std::size_t x) {
            int left = left_child_index(x);
            return structure[left];
        }

        inline int right_child(std::size_t x) {
            int left = right_child_index(x);
            return structure[left];
        }

        inline T value_at(std::size_t at) {
            return origin[at];
        }

    };

    template <class T>
    class LazySegmentTree
    {
    protected:
        std::vector<T> &origin;
        std::vector<T> structure;
        std::vector<T> lazy;

        /**
         * This function is used build the segment tree with a binary heap
         * implementation, and it use the origin array stored in the class.
         * @tparam T is the type of structure, usually it is a int or another numeric type
         * @param left_index the left index of the range
         * @param right_index the right index of the range
         */
        void build_structure(std::size_t left_index, std::size_t right_index)
        {
            build_structure_procedure(1, left_index, right_index - 1);
        }
        /**
         * This is the sub procedure that help the build_structure procedure to make the logic inside the segment tree
         * this version store inside the node of Segment Tree the value and not the index of the value
         * @tparam T is the type of structure, usually it is a int or another numeric type
         * @param start_index
         * @param left_index
         * @param right_index
         */
        void build_structure_procedure(std::size_t start_index, std::size_t left_index, std::size_t right_index)
        {
            if (left_index == right_index) {
                // Leaf node will have a single element
                structure[start_index] = origin[left_index];
                return;
            }
            auto middle_point = (left_index + right_index) / 2;
            auto left_child = left_child_index(start_index);
            auto right_child = right_child_index(start_index);
            build_structure_procedure(left_child, left_index, middle_point);
            build_structure_procedure(right_child, middle_point + 1, right_index);
            // Internal node will have the sum of both of its children
            auto segment_left = structure[left_child];
            auto segment_right = structure[right_child];
            structure[start_index] = (segment_left <= segment_right) ? segment_left : segment_right;
        }

        T range_query_subroutine(std::size_t start_index, std::size_t left_index, std::size_t right_index, std::size_t query_left, std::size_t query_right)
        {
            propagate(start_index, left_index, right_index);
            // outside the range
            if (query_left > query_right)  return -1;
            // range represented by a node is completely inside the given range
            if (left_index >= query_left && right_index <= query_right)  return structure[start_index];
            // range represented by a node is partially inside and partially outside the given range
            auto middle_point = (left_index + right_index) / 2;
            auto left_child = left_child_index(start_index);
            auto right_child = right_child_index(start_index);
            auto left_segment = range_query_subroutine(left_child, left_index, middle_point,
                                                       query_left, std::min(middle_point, query_right));
            auto right_segment = range_query_subroutine(right_child, middle_point + 1, right_index,
                                                        std::max(query_left, middle_point + 1), query_right);
            if (left_segment == -1) return right_segment;
            if (right_segment == -1) return left_segment;
            return std::min(left_segment, right_segment);
        }

        /**
         * Perform the real update of the update_range operation,
         * @param start_index: Start index, at the starting point this is 1
         * @param left_index: At the starting point it is the first position of the original array, so 0.
         * @param right_index: At the starting point it is the last position of the original array, so size - 1
         * @param from: The start index where start to update original array
         * @param to: The end index where stop to update original array
         * @param new_val: The value to sum to each position of the range in the original array.
         */
        void update_range_subroutine(std::size_t start_index, std::size_t left_index, std::size_t right_index,
                                     std::size_t from, std::size_t to, T new_val)
        {
            propagate(start_index, left_index, right_index);
            if (from > to) return;
            if((left_index >= from) && (right_index <= to)) {
                lazy[start_index] = new_val;
                propagate(start_index, left_index, right_index);
            } else {
                auto middle_point = (left_index + right_index) / 2;
                auto left_child = left_child_index(start_index);
                auto right_child = right_child_index(start_index);
                update_range_subroutine(left_child, left_index, middle_point, from, std::min(middle_point, to), new_val);
                update_range_subroutine(right_child, middle_point + 1, right_index,
                                        std::max(from, middle_point + 1), to, new_val);
                auto left_subtree = (lazy[left_child] != -1) ? lazy[left_child] : structure[left_child];
                auto right_subtree = (lazy[right_child] != -1) ? lazy[right_child] : structure[right_child];
                structure[start_index] = (left_subtree <= right_subtree) ? structure[left_child] : structure[right_child];
            }
        }

        void propagate(std::size_t start_index, std::size_t left_index, std::size_t right_index)
        {
            if (lazy[start_index] != -1) {
                // The node in position start_index was marked as lazy
                structure[start_index] = lazy[start_index];
                if (left_index != right_index) {
                    auto left_child = left_child_index(start_index);
                    auto right_child = right_child_index(start_index);
                    lazy[left_child] = lazy[right_child] = lazy[start_index];
                } else {
                    // left_index = right_index is the time to update the origin array
                    origin[left_index] = lazy[start_index];
                }
                // mark as the node as not lazy
                lazy[start_index] = -1;
            }
        }

        std::size_t left_child_index(const std::size_t index)
        {
            return index * 2;
        }

        std::size_t right_child_index(const std::size_t index)
        {
            return (index * 2) + 1;
        }

    public:
        LazySegmentTree(std::vector<T> &origin): origin(origin)
        {
            std::size_t size = origin.size();
            structure = std::vector<T>(size * 4);
            lazy = std::vector<T>(size * 4, -1);
            origin = origin;
            build_structure(0, size);
        }

        virtual ~LazySegmentTree()
        {
            structure.clear();
            lazy.clear();
        }

        T range_query(std::size_t start_index, std::size_t end_index)
        {
            return range_query_subroutine(1, 0, origin.size() - 1, start_index, end_index);
        }

        /**
         * This procedure update the value stored inside the structure in one single position, this use the
         * update_range_subroutine with from == to == at; to run the procedure update
         * @param at: it is the position in the original array, the function change the value also in the original array
         * @param new_value the value that we want override in position at.
         */
        void update(std::size_t at, T value)
        {
            update_range_subroutine(1, 0, origin.size() - 1, at, at, value);
        }

        /**
         * Update the range with with the sum operation to the original array,
         * This function will modify the original array original[pos] += new_val.
         * @param from: Start position where start to update the original array.
         * @param to: End position where stop to update the original array.
         * @param new_val: The value to sum to each position of the range in the original array.
         */
        void update_range(std::size_t from, std::size_t to, T new_val)
        {
            update_range_subroutine(1, 0, origin.size() - 1, from, to, new_val);
        }

        T get_elem(std::size_t at)
        {
            return origin[at];
        }
    };
};

template<typename T>
struct Query {
    bool update;
    T start;
    T end;

    Query(bool type, T start, T anEnd) : update(type), start(start), end(anEnd) {}
};

template <typename T>
std::vector<T> range_minimum_query_segment_tree(cpstl::SegmentTree<T> &segmentTree, std::vector<Query<T>> &queries)
{
    std::vector<T> results;
    results.reserve(queries.size());
    for (auto &query : queries) {
        if (query.update) {
            segmentTree.update(query.start - 1, query.end);
            continue;
        }
        auto res = segmentTree.range_query(query.start - 1, query.end - 1);
        results.push_back(segmentTree.value_at(res));
    }
    return results;
}

template <typename T>
std::vector<T> range_minimum_query_lazy_segment_tree(cpstl::LazySegmentTree<T> &segmentTree, std::vector<Query<T>> &queries)
{
    std::vector<T> results;
    results.reserve(queries.size());
    for (auto &query : queries) {
        if (query.update) {
            segmentTree.update(query.start - 1, query.end);
            continue;
        }
        auto res = segmentTree.range_query(query.start - 1, query.end - 1);
        results.push_back(res);
    }
    return results;
}

int main() {
    int N, Q;
    scanf("%d", &N);
    scanf("%d", &Q);

    std::vector<int> inputs;
    inputs.reserve(N);
    //Read the array
    for (std::size_t t = 0; t < N; t++) {
        int value;
        scanf("%d", &value);
        inputs.push_back(value);
    }

    std::vector<Query<int>> queries;
    queries.reserve(Q);
    //read query
    for (int i = 0; i < Q; i++) {
        char type;
        int start, end;
        cin >> type;
        scanf("%d", &start);
        scanf("%d", &end);
        if (type == 'u') {
            queries.emplace_back(true, start, end);
            continue;
        }
        queries.emplace_back(false, start, end);
    }

    auto segment_tree = cpstl::SegmentTree<int>(inputs);
    auto result = range_minimum_query_segment_tree(segment_tree, queries);
    for (auto res : result) {
        printf("%d\n", res);
    }
}
