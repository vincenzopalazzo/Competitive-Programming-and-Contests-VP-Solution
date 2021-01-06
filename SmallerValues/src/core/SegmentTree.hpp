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
        std::vector<T> &origin;
        std::vector<std::vector<T>> structure;

        void build_structure(int left_index, int right_index)
        {
            build_structure_procedure(1, left_index, right_index - 1);
        }

        void build_structure_procedure(int start_index, int left_index, int right_index)
        {
            if (left_index == right_index) {
                // Leaf node will have a single element
                structure[start_index] = {origin[left_index]};
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
            segment_left.insert(segment_left.end(), segment_right.begin(), segment_right.end());
            structure[start_index] = segment_left;
        }

        std::vector<T> range_query_subroutine(int start_index, int left_index_now, int right_index_now, int query_left, int query_right)
        {
            if (query_left > right_index_now || query_right < left_index_now)  return {}; // outside the range
            if (left_index_now >= query_left && right_index_now <= query_right)  return structure[start_index]; // range represented by a node is completely inside the given range
            // range represented by a node is partially inside and partially outside the given range
            auto middle_point = (left_index_now + right_index_now) / 2;
            auto left_child = left_child_index(start_index);
            auto right_child = right_child_index(start_index);
            auto left_segment = range_query_subroutine(left_child, left_index_now, middle_point,
                                                      query_left, query_right);
            auto right_segment = range_query_subroutine(right_child, middle_point + 1, right_index_now,
                                                       query_left, query_right);
            if (left_segment.empty()) return right_segment;
            if (right_segment.empty()) return left_segment;
            left_segment.insert(left_segment.end(), right_segment.begin(), right_segment.end());
            return left_segment;
        }

        void update_subroutine(int start_index, int left_index, int right_index, int pos, T new_value)
        {
            if (left_index == right_index) {
                origin[pos] = new_value;
                structure[start_index] = pos;
            } else {
                int middle_point = (left_index + right_index) / 2;
                auto left_child = left_child_index(start_index);
                auto right_child = right_child_index(start_index);
                if (pos <= middle_point) {
                    update_subroutine(left_child, left_index, middle_point, pos, new_value);
                }else {
                    update_subroutine(right_child, middle_point + 1, right_index, pos, new_value);
                }
                auto segment_left = structure[left_child];
                auto segment_right = structure[right_child];
                structure[start_index] = segment_left.insert(segment_left.end(), segment_right.begin(), segment_right.end());
            }
        }

        inline int left_child_index(const int index)
        {
            return index * 2;
        }

        inline int right_child_index(const int index)
        {
            return (index * 2) + 1;
        }
    public:

        SegmentTree(std::vector<T> &origin): origin(origin)
        {
            int size = origin.size();
            structure = std::vector<std::vector<T>>(size * 4);
            origin = origin;
            build_structure(0, size);
        }

        virtual ~SegmentTree()
        {
            structure.clear();
        }

        std::vector<T> range_query(int start_index, int end_index)
        {
            return range_query_subroutine(1, 0, origin.size() - 1, start_index, end_index);
        }

        void update(int at, T value)
        {
            update_subroutine(1, 0, origin.size() - 1, at, value);
        }
    };
};

#endif //RBTREE_SEGMENTTREE_H
