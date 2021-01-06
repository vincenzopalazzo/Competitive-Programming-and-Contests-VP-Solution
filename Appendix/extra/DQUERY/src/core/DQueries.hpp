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
    T start;
    T end;
    T original_index;
    // Wrong position but I need this to implement the MO's
    // algorithm without a shit algorithm
    std::size_t block_size;

    Query(T start, T anEnd, T originalIndex, std::size_t blockSize) : start(start), end(anEnd), original_index(originalIndex),
                                                            block_size(std::sqrt(blockSize)) {}
};

template<typename T>
static bool comparison(Query<T> &left_query, Query<T> &right_query)
{
    auto left_block = (left_query.start / static_cast<T>(555));
    auto right_block = (right_query.start / static_cast<T>(555));
    if (left_block != right_block)
        // different blocks, so sort by block.
        return left_block < right_block;
    // same block, so sort by end (R) value
    return left_query.end < right_query.end;
}

template<typename T, typename R>
static void increase(std::vector<T> const &input, std::vector<T> &counter, R &result, T position)
{
    auto to_count = input[position];
    counter[to_count]++;
    if (counter[to_count] == 1) {
        result++;
    }
}

template<typename T, typename R>
static void decrease(std::vector<T> const &input, std::vector<T> &counter, R &result, T position)
{
    auto to_count = input[position];
    counter[to_count]--;
    if (counter[to_count] == 0) {
        result--;
    }
}

template <typename T, typename R>
static std::vector<R> count_distinct_item_mo(std::vector<T> const &inputs, std::vector<Query<T>> &queries)
{
    std::vector<R> result(queries.size(), 0);
    //1. Sort the order of the query
    std::sort(queries.begin(), queries.end(), comparison<T>);

    // This is necessary to know the maximum element of the
    // queries (R element) to create the result vector
    auto max_index = 0;
    for (auto &query : queries) {
        if (max_index < query.end)
            max_index = query.end;
    }

    // to be safe we call 2*max_index
    std::vector<R> counter(2 * max_index, 0);
    // Two pointer technique
    T current_left = 0;
    T current_right = 0;
    R query_result = 0;

    for (auto &query: queries) {
        // -1 because the query are indexed from 1
        T left_point = query.start - 1;
        T right_point = query.end - 1;

        // while the current l is greater than the next query's l , add the element into the range
        while (current_left < left_point) {
            // decrement l and then add the new element
            decrease<T, R>(inputs, counter, query_result, current_left);
            current_left++;
        }

        // while the current l is lesser than the next query's l , remove the element from the range
        while (current_left > left_point) {
            increase<T, R>(inputs, counter, query_result, current_left);
            current_left--;
        }

        // while the current r is leseer than the next query's r, add the element into the range
        while (current_right <= right_point) {
            increase<T, R>(inputs, counter, query_result, current_right);
            current_right++;
        }

        while (current_right > (right_point + 1)) {
            decrease<T, R>(inputs, counter, query_result, current_right - 1);
            current_right--;
        }
        result[query.original_index] = query_result;
    }

    return result;
}

