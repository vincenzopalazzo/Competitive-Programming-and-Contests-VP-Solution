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
#include <vector>
#include <iostream>

namespace cpstl
{
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
            return std::max(left_segment, right_segment);
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
                structure[start_index] = (left_subtree >= right_subtree) ? structure[left_child] : structure[right_child];
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
};