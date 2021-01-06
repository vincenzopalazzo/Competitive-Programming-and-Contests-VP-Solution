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

template<typename T>
struct Query {
    std::size_t start;
    std::size_t end;
    T value;

    Query(size_t start, size_t anEnd, T value) : start(start), end(anEnd), value(value) {}
};

template <typename T, typename R>
static std::vector<R> smaller_value_mo_algorithms(std::vector<T> const &inputs, std::vector<Query<T>> const &queries)
{
    return {};
}

template <typename T, typename R>
static std::vector<R> smaller_value_fenwick_tree(std::vector<T> &inputs, std::vector<Query<T>> const &queries)
{
    return {};
}

template <typename T, typename R>
static std::vector<R> smaller_value_segment_tree(std::vector<T> &inputs, std::vector<Query<T>> const &queries)
{
    auto segment_tree = cpstl::SegmentTree<T>(inputs);
    std::vector<T> result;
    result.reserve(queries.size());
    for (auto query: queries) {
        auto query_result = 0;
        auto range = segment_tree.range_query(query.start, query.end);
        cpstl::cp_log(LOG, range);
        for (auto elem : range) {
            cpstl::cp_log(LOG, std::to_string(elem) + " <=" + std::to_string(query.value));
            if (elem <= query.value)
                query_result++;
        }
        result.push_back(query_result);
    }

    return result;
}



