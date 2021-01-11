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

const cpstl::Log LOG(true);

template<typename T>
struct Query {
    std::size_t subtree;
    T color;
    std::size_t index_query;
    std::size_t block_size;

    Query(size_t subtree, T color, size_t indexQuery, size_t blockSize) : subtree(subtree), color(color),
                                                                          index_query(indexQuery),
                                                                          block_size(std::sqrt(blockSize)) {}
};

struct Edge {
    std::size_t from;
    std::size_t to;

    Edge(size_t from, size_t to) : from(from), to(to) {}
};

template<typename T>
static bool compare(Query<T> const &query_a, Query<T> const &query_b)
{
    auto left_block = query_a.subtree / query_a.block_size;
    auto right_block = query_b.subtree / query_b.block_size;
    return left_block < right_block;
}

template<typename T, typename R>
static void increment(std::vector<T> const &input, std::map<T, R> counter, R &answer, std::size_t position)
{
    auto to_pos = input[position];
    answer -= counter[to_pos];
    counter[to_pos]++;
    answer += counter[to_pos];
}

template<typename T, typename R>
static void decrement(std::vector<T> const &input, std::map<T, R> counter, R &answer, std::size_t position)
{
    auto to_pos = input[position];
    answer -= counter[to_pos];
    counter[to_pos]--;
    answer += counter[to_pos];
}

template <typename T>
static std::vector<T> remap_tree_into_array(std::vector<T> const &inputs, std::vector<Edge> const &edges)
{
    std::vector<T> remap_vector;

    return remap_vector;
}

template <typename T, typename R>
static std::vector<R> numbers_of_vertices_with_color(std::vector<T> const &inputs, std::vector<Edge> const &edges,
                                                     std::vector<Query<T>> &queries)
{
    auto tree_remapped = remap_tree_into_array(inputs, edges);

    std::sort(queries.begin(), queries.end(), compare<T>);

    std::vector<R> result(queries.size(), 0);
    std::map<T, R> counter;
    std::size_t current_left = 0;
    std::size_t current_right = 0;
    R answer = 0;
    for (auto query : queries) {
        auto left_point = 0;
        auto right_point = query.subtree - 1;

        while (current_left > left_point) {
            increment(inputs, counter, answer, current_left);
            current_left--;
        }

        while (current_left < left_point) {
            decrement(inputs, counter, answer, current_left);
            current_left++;
        }

        while (current_right < right_point) {
            increment(inputs, counter, answer, current_right);
            current_right++;
        }

        while (current_right > (right_point + 1)) {
            decrement(inputs, counter, answer, current_right - 1);
            current_right--;
        }
        result[query.index_query] = answer;
    }
    return result;
}

