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
#include <cassert>
#include "FenwickTree.h"

template<class T>
void cpstl::BTreeIndex<T>::update(const T &value, int at)
{
    assert(at > 0 && "The position inside the array should be greater than 0");
    while (at < structure.size()) {
        structure[at] += value;
        at += indexing(at);
    }
}

template<class T>
T cpstl::BTreeIndex<T>::sum(int begin, int end)
{
    assert(begin >= 0 && end >= 0);
    T sum = 0;
    int at = end;
    while (at > begin) {
        sum += structure[at];
        at &= at - 1;
        //at -= indexing(at);
    }
    return sum;
}

template<class T>
T cpstl::BTreeIndex<T>::sum(int end)
{
    assert(end >= 0);
    T sum = 0;
    int at = end;
    while (at > 0) {
        sum += structure[at];
        at &= at -1;
        //at -= indexing(at);
    }
    return sum;
}

template<class T>
int cpstl::BTreeIndex<T>::min(T const value) {
    return -1;
}

template<class T>
int cpstl::BTreeIndex<T>::max(T const value) {
    return -1;
}

template<class T>
int cpstl::BTreeIndex<T>::indexing(int index)
{
    return index& -index;
}

template<class T>
cpstl::BTreeIndex<T>::BTreeIndex(int size)
{
    structure = std::vector<T>(size + 1);
}

template<class T>
cpstl::BTreeIndex<T>::BTreeIndex(const std::vector<T> &structure)
{
    this->structure.reserve(structure.size() + 1);
    this->structure[0] = 0;
    for (int i = 0; i < structure.size(); i++) {
        this->structure[i + 1] = structure[i];
    }

    int at = 1;
    while (at < this->structure.size()) {
        int at_tree = indexing(at);
        this->structure[at_tree] += this->structure[at];
        at += indexing(at);
    }
}

template class cpstl::BTreeIndex<int>;