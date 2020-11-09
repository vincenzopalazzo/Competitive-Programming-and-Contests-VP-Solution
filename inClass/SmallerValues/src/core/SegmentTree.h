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

namespace cpstl
{
    template <class T>
    class SegmentTree
    {
    private:
        /**
         * This store the reference of the origin array to managed the update operation
         * and maintain the array in sync.
         *
         * ALERT this is correct for a c++ idea? it look like yes?
         */
        std::vector<T> &origin;
        std::vector<T> structure;

        /**
         * This function is used build the segment tree with a binary heap
         * implementation, and it use the origin array stored in the class.
         * @tparam T is the type of structure, usually it is a int or another numeric type
         * @param left_index the left index of the range
         * @param right_index the right index of the range
         */
        void build_structure(size_t left_index, size_t right_index, T flag);
        /**
         * This is the sub procedure that help the build_structure procedure to make the logic inside the segment tree
         * @tparam T is the type of structure, usually it is a int or another numeric type
         * @param start_index
         * @param left_index
         * @param right_index
         */
        void build_structure_procedure(size_t start_index, size_t left_index, size_t right_index, T flag);

        int range_query_subroutine(size_t start_index, size_t left_index_now, size_t right_index_now, size_t query_left, size_t query_right);

        inline size_t left_child_index(size_t const index)
        {
            return index << 1;
        }

        inline size_t right_child_index(size_t const index)
        {
            return (index << 1) + 1;
        }
    public:

        /**
         * This constructor bring a normal vector and build under the hood the
         * the segment tree with binary heap implementation
         * @param inputs
         */
        SegmentTree(std::vector<T> &origin, T flag);

        virtual ~SegmentTree();

        int range_query(size_t start_index, size_t end_index);

        inline size_t left_child(size_t x)
        {
            size_t left = left_child_index(x);
            return structure[left];
        }

        inline size_t right_child(size_t x)
        {
            size_t left = right_child_index(x);
            return structure[left];
        }

    };
};

#endif //RBTREE_SEGMENTTREE_H
