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
#include <cstdlib>
#include <string>
#include <vector>
#include "../test/Utils.hpp"
#include "FenwickTree.hpp"
#include "SegmentTree.hpp"

const cpstl::Log LOG(true);

template<typename T>
struct Segment {
    T x_coordinate;
    T y_coordinate;
    size_t index;

    Segment(T xCoordinate, T yCoordinate, size_t index) : x_coordinate(xCoordinate), y_coordinate(yCoordinate),
                                                          index(index) {}
};

template<typename T>
static cpstl::BTreeIndex<T> precompute_into_fenwick_tree(std::vector<Segment<T>> &inputs)
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

    auto fenwick_tree = cpstl::BTreeIndex<T>(indexes.size());
    for (auto &segment : inputs) {
        fenwick_tree.update(segment.y_coordinate, 1);
    }
    return fenwick_tree;
}

template <typename T, typename R>
static std::vector<R> nested_segment_fenwick_tree(std::vector<Segment<T>> &inputs)
{
    auto fenwick_tree = precompute_into_fenwick_tree(inputs);
    std::vector<R> result(inputs.size(), 0);
    for (auto &segment : inputs) {
        auto nested_segment = fenwick_tree.sum(segment.y_coordinate) - 1;
        fenwick_tree.update(segment.y_coordinate, -1);
        result[segment.index] = nested_segment;
    }
    return result;
}

