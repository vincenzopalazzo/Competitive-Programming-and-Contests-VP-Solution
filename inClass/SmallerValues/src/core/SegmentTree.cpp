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
#include <iostream>
#include "SegmentTree.h"

using namespace cpstl;


template<class T>
void SegmentTree<T>::build_structure(size_t left_index, size_t right_index, T flag)
{
    build_structure_procedure(1, left_index, right_index - 1, flag);
}

template<class T>
void SegmentTree<T>::build_structure_procedure(size_t start_index, size_t left_index, size_t right_index, T flag)
{
    if (left_index == right_index) {
        structure[start_index] = left_index;
        return;
    }
    int middle_point = (left_index + right_index) / 2;
    int left_child = left_child_index(start_index);
    int right_child = right_child_index(start_index);
    build_structure_procedure(left_child, left_index, middle_point, flag);
    build_structure_procedure(right_child, middle_point + 1, right_index, flag);
    int segment_left = structure[left_child];
    int segment_right = structure[right_child];
    int smaller_elem = 0;
    smaller_elem += origin[segment_left] < flag ?  1 : 0;
    smaller_elem += origin[segment_right] < flag ? 1 : 0;
    structure[start_index] = smaller_elem;
}

template<class T>
int SegmentTree<T>::range_query(size_t start_index, size_t end_index) {
    return range_query_subroutine(1, 0, origin.size() - 1,
                                  start_index, end_index);
}

template<class T>
int SegmentTree<T>::range_query_subroutine(size_t start_index, size_t left_index_now, size_t right_index_now,
                                           size_t query_left, size_t query_right)
{
    return structure[start_index];
}

template<class T>
SegmentTree<T>::SegmentTree(std::vector<T> &origin, T flag): origin(origin)
{
    int size = origin.size();
    structure = std::vector<T>(size * 4);
    origin = origin;
    build_structure(0, size, flag);
}

template<class T>
SegmentTree<T>::~SegmentTree()
{
    structure.clear();
}


template class cpstl::SegmentTree<int>;