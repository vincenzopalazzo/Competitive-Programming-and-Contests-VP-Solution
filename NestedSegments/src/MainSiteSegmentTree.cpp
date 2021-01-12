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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
    template <class T>
    class LazySegmentTree
    {
    protected:
        std::size_t origin_size;
        std::vector<T> structure;
        std::vector<T> lazy;

        T range_query_subroutine(std::size_t start_index, std::size_t left_index, std::size_t right_index, std::size_t query_left, std::size_t query_right)
        {
            propagate(start_index, left_index, right_index);
            // outside the range
            if (query_left > query_right)  return INT32_MIN;
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

            if (left_segment == INT32_MIN) return right_segment;
            if (right_segment == INT32_MIN) return left_segment;
            return left_segment + right_segment;
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
                auto left_subtree = (lazy[left_child] != INT32_MIN) ? lazy[left_child] : structure[left_child];
                auto right_subtree = (lazy[right_child] != INT32_MIN) ? lazy[right_child] : structure[right_child];
                structure[start_index] = left_subtree + right_subtree;
            }
        }

        void propagate(std::size_t start_index, std::size_t left_index, std::size_t right_index)
        {
            if (lazy[start_index] != INT32_MIN) {
                // The node in position start_index was marked as lazy
                structure[start_index] += lazy[start_index];
                if (left_index != right_index) {
                    auto left_child = left_child_index(start_index);
                    auto right_child = right_child_index(start_index);
                    lazy[left_child] = lazy[right_child] = lazy[start_index];
                }
                // mark as the node as not lazy
                lazy[start_index] = INT32_MIN;
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
        LazySegmentTree(std::size_t const size): structure(size * 4),
                                                 lazy(size * 4, INT32_MIN),
                                                 origin_size(size) { }

        virtual ~LazySegmentTree()
        {
            structure.clear();
            lazy.clear();
        }

        T range_query(std::size_t start_index, std::size_t end_index)
        {
            return range_query_subroutine(1, 0, origin_size - 1, start_index, end_index);
        }

        /**
         * This procedure update the value stored inside the structure in one single position, this use the
         * update_range_subroutine with from == to == at; to run the procedure update
         * @param at: it is the position in the original array, the function change the value also in the original array
         * @param new_value the value that we want override in position at.
         */
        void update(std::size_t at, T value)
        {
            update_range_subroutine(1, 0, origin_size - 1, at, at, value);
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
            update_range_subroutine(1, 0, origin_size - 1, from, to, new_val);
        }
    };

    template <class T>
    class SegmentTree
    {
    private:
        std::size_t original_size;
        std::vector<T> structure;

        int range_query_subroutine(int start_index, int left_index_now, int right_index_now, int query_left, int query_right)
        {
            if (query_left > right_index_now || query_right < left_index_now)  return INT32_MIN; // outside the range
            if (left_index_now >= query_left && right_index_now <= query_right)  return structure[start_index]; // range represented by a node is completely inside the given range
            // range represented by a node is partially inside and partially outside the given range
            int middle_point = (left_index_now + right_index_now) / 2;
            int left_child = left_child_index(start_index);
            int right_child = right_child_index(start_index);
            int left_segment = range_query_subroutine(left_child, left_index_now, middle_point,
                                                      query_left, query_right);
            int right_segment = range_query_subroutine(right_child, middle_point + 1, right_index_now,
                                                       query_left, query_right);
            if (left_segment == INT32_MIN) return right_segment;
            if (right_segment == INT32_MIN) return left_segment;
            return left_segment + right_segment;
        }

        void update_subroutine(int start_index, int left_index, int right_index, int pos, T new_value)
        {
            if (left_index == right_index) {
                structure[start_index] += new_value;
            } else {
                int middle_point = (left_index + right_index) / 2;
                int left_child = left_child_index(start_index);
                int right_child = right_child_index(start_index);
                if (pos <= middle_point) {
                    update_subroutine(left_child, left_index, middle_point, pos, new_value);
                } else {
                    update_subroutine(right_child, middle_point + 1, right_index, pos, new_value);
                }
                int segment_left = structure[left_child];
                int segment_right = structure[right_child];
                structure[start_index] = segment_left + segment_right;
            }
        }

        inline int left_child_index(const int index)
        {
            //return index << 1;
            return index * 2;
        }

        inline int right_child_index(const int index)
        {
            //return (index << 1) + 1;
            return (index * 2) + 1;
        }
    public:

        SegmentTree(std::size_t size): original_size(size)
        {
            structure = std::vector<T>(size * 4);
        }

        virtual ~SegmentTree()
        {
            structure.clear();
        }

        int range_query(int start_index, int end_index)
        {
            return range_query_subroutine(1, 0, original_size - 1, start_index, end_index);
        }

        /**
         * This is the sub procedure that help the build_structure procedure to make the logic inside the segment tree
         * @param at: it is the position in the original array, the function change the value also in the original array
         * @param new_value the value that we want override in position at.
         */
        void update(int at, T value)
        {
            update_subroutine(1, 0, original_size - 1, at, value);
        }
    };
};

template<typename T>
struct Segment {
    T x_coordinate;
    T y_coordinate;
    size_t index;

    Segment(T xCoordinate, T yCoordinate, size_t index) : x_coordinate(xCoordinate), y_coordinate(yCoordinate),
                                                          index(index) {}
};

template<typename T>
static std::vector<T> remap_input_with_rank(std::vector<Segment<T>> &inputs)
{
    //Compute the maximum index inside the segment
    std::vector<T> indexes;
    for (auto &segment : inputs) {
        indexes.push_back(segment.x_coordinate);
        indexes.push_back(segment.y_coordinate);
    }
    std::sort(indexes.begin(), indexes.end());

    for (auto &segment: inputs) {
        // lower_bound get the first element that is smaller that segment.x_coordinate
        auto x_iterator = std::lower_bound(indexes.begin(), indexes.end(), segment.x_coordinate);
        // lower_bound get the first element that is smaller that segment.y_coordinate
        auto y_iterator = std::lower_bound(indexes.begin(), indexes.end(), segment.y_coordinate);
        //What this operation does
        segment.x_coordinate = static_cast<T>(x_iterator - indexes.begin());
        segment.y_coordinate = static_cast<T>(y_iterator - indexes.begin());
    }

    std::sort(inputs.begin(), inputs.end(), [](auto &segment_a, auto &segment_b){
        return segment_a.x_coordinate < segment_b.x_coordinate;
    });
    return indexes;
}

template<typename T>
static cpstl::LazySegmentTree<T> precompute_into_lazy_segment_tree(std::vector<Segment<T>> &inputs) {

    auto rank_remap = remap_input_with_rank(inputs);
    auto segment_tree = cpstl::LazySegmentTree<T>(rank_remap.size());
    for (auto &segment : inputs) {
        segment_tree.update(segment.y_coordinate, 1);
    }
    return segment_tree;
}

template<typename T, typename R>
static std::vector<R> nested_segment_lazy_segment_tree(std::vector<Segment<T>> &inputs)
{
    auto segment_tree = precompute_into_lazy_segment_tree(inputs);
    std::vector<R> results(inputs.size(), 0);
    for (auto segment : inputs) {
        results[segment.index] = segment_tree.range_query(segment.x_coordinate, segment.y_coordinate) - 1;
        segment_tree.update(segment.y_coordinate, -1);
    }
    return results;
}

template<typename T>
static cpstl::SegmentTree<T> precompute_into_segment_tree(std::vector<Segment<T>> &inputs) {

    auto rank_remap = remap_input_with_rank(inputs);
    auto segment_tree = cpstl::SegmentTree<T>(rank_remap.size());
    for (auto &segment : inputs) {
        segment_tree.update(segment.y_coordinate, 1);
    }
    return segment_tree;
}

template<typename T, typename R>
static std::vector<R> nested_segment_segment_tree(std::vector<Segment<T>> &inputs)
{
    auto segment_tree = precompute_into_segment_tree(inputs);
    std::vector<R> results(inputs.size(), 0);
    for (auto segment : inputs) {
        results[segment.index] = segment_tree.range_query(segment.x_coordinate, segment.y_coordinate) - 1;
        segment_tree.update(segment.y_coordinate, -1);
    }
    return results;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::size_t N;
    scanf("%ld", &N);

    std::vector<Segment<long long>> inputs;
    inputs.reserve(N);
    //Read the array
    for (std::size_t index = 0; index < N; index++) {
        long long x;
        long long y;
        scanf("%lld", &x);
        scanf("%lld", &y);
        inputs.emplace_back(x, y, index);
    }

    //auto result = nested_segment_lazy_segment_tree<long long, long long>(inputs);
    auto result = nested_segment_segment_tree<long long, long long>(inputs);
    for (auto res : result)
        printf("%lld\n", res);
}

