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
#ifndef RBTREE_SEGMENTTREE_H
#define RBTREE_SEGMENTTREE_H

#include <vector>

//Reference implementation https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/
namespace cpstl
{
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

#endif //RBTREE_SEGMENTTREE_H
