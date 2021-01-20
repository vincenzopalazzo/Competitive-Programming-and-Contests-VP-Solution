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
#include "SegmentTree.hpp"

const cpstl::Log LOG(true);

template <typename T>
struct Query {
    T value;
    std::size_t at;
    bool update;

    Query(T value) : value(value) {
        update = false;
        at = -1;
    }

    Query(T value, size_t at) : value(value), at(at) {
        update = true;
    }
};

template <typename T, typename R>
static std::vector<R> find_number_of_zeros(std::vector<T> &inputs, std::vector<Query<T>> const &queries)
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

