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
    std::size_t index = -1;
    std::size_t block_size;

    Query(std::size_t start, std::size_t anEnd, T value) : start(start), end(anEnd), value(value) {}

    Query(size_t start, size_t anEnd, T value, size_t index, size_t blockSize) : start(start), end(anEnd), value(value),
                                                                                 index(index),
                                                                                 block_size(std::sqrt(blockSize)) {}
};

template<typename T>
static bool compare(Query<T> const &query_a, Query<T> const &query_b) {
    auto left_block = query_a.start / query_a.block_size;
    auto right_block = query_b.start / query_b.block_size;
    if (left_block != right_block)
        return left_block < right_block;
    return query_a.end < query_b.end;
}

template<typename T, typename R>
static void increment(std::vector<T> const &inputs,  T value, R &answer, std::size_t position)
{
    auto to_position = inputs[position];
    if (to_position <= value)
        answer++;
}

template<typename T, typename R>
static void decrement(std::vector<T> const &inputs, T value, R &answer, std::size_t position)
{
    auto to_position = inputs[position];
    if (to_position > value)
        answer--;
}

template <typename T, typename R>
static std::vector<R> smaller_value_mo_algorithms(std::vector<T> const &inputs, std::vector<Query<T>> &queries)
{
    std::vector<R> results(queries.size(), 0);
    std::sort(queries.begin(), queries.end(), compare<T>);

    std::size_t current_left = 0;
    std::size_t current_right = 0;
    R answer = 0;

    for (auto query : queries) {
        auto left_query = query.start;
        auto right_query = query.end;
        auto value_query = query.value;

        while (current_left > left_query) {
            increment(inputs, value_query, answer, current_left);
            current_left--;
        }

        while (current_left < left_query) {
            decrement(inputs, value_query, answer, current_left - 1);
            current_left++;
        }

        while (current_right <= right_query) {
            increment(inputs, value_query, answer, current_right);
            current_right++;
        }

        while (current_right > (right_query + 1)) {
            decrement(inputs, value_query, answer, current_right -1);
            current_right--;
        }
        results[query.index] = answer;
    }

    return results;
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
        for (auto elem : range) {
            if (elem <= query.value)
                query_result++;
        }
        result.push_back(query_result);
    }
    return result;
}



