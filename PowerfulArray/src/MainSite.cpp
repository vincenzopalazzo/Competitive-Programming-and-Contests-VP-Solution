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
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


struct Query {
    std::size_t start;
    std::size_t end;
    std::size_t size_block;
    std::size_t query_index;

    Query(size_t start, size_t anEnd, size_t sizeBlock, size_t queryIndex) : start(start), end(anEnd),
                                                                             size_block(std::sqrt(sizeBlock)),
                                                                             query_index(queryIndex) {}
};

static bool compare(Query &query_a, Query &query_b)
{
    auto left_block = query_a.start / query_a.size_block;
    auto right_block = query_b.start / query_a.size_block;
    if (left_block != right_block)
        return left_block < right_block;
    return query_a.end < query_b.end;
}

template <typename T, typename R>
static void increment(std::vector<T> const &inputs, std::vector<T> &frequency, R &answer, std::size_t position)
{
    auto to_position = inputs[position];
    answer -= std::pow(frequency[to_position], 2) * to_position;
    frequency[to_position]++;
    answer += std::pow(frequency[to_position], 2) * to_position;
}

template <typename T, typename R>
static void decrement(std::vector<T> const &inputs, std::vector<T> &frequency, R &answer, std::size_t position)
{
    auto to_position = inputs[position];
    answer -= std::pow(frequency[to_position], 2) * to_position;
    frequency[to_position]--;
    answer += std::pow(frequency[to_position], 2) * to_position;
}

template <typename T, typename R>
static std::vector<R> powerful_array_mo_algorithms(std::vector<T> const &inputs, std::vector<Query> &queries)
{
    std::vector<R> results(queries.size(), 0);

    // First step in mo algorithm is to sort the queries in the
    // decreasing order by compare logic in the method above
    std::sort(queries.begin(), queries.end(), compare);


    std::size_t current_left = 0;
    std::size_t current_right = 0;
    std::vector<T> frequency(1000001, 0);
    R query_result = 0;
    for (auto query : queries) {
        auto left_query = query.start - 1;
        auto right_query = query.end - 1;

        while (current_left < left_query) {
            decrement<T, R>(inputs, frequency, query_result, current_left);
            current_left++;
        }

        while (current_left > left_query) {
            increment<T, R>(inputs, frequency, query_result, current_left + 1);
            current_left--;
        }

        while (current_right <= right_query) {
            increment<T, R>(inputs, frequency, query_result, current_right);
            current_right++;
        }

        while (current_right > right_query + 1) {
            decrement<T, R>(inputs, frequency, query_result, current_right - 1);
            current_right--;
        }
        results[query.query_index] = query_result;
    }
    return results;
}

int main() {
    int N, Q;
    scanf("%d", &N);
    scanf("%d", &Q);

    std::vector<int> inputs;
    inputs.reserve(N);
    //Read the array
    for (std::size_t t = 0; t < N; t++) {
        int value;
        scanf("%d", &value);
        inputs.push_back(value);
    }

    std::vector<Query> queries;
    queries.reserve(Q);
    //Read the array
    for (std::size_t t = 0; t < Q; t++) {
        int x, y;
        scanf("%d%d", &x, &y);
        queries.emplace_back(x, y, inputs.size(), t);
    }

    auto results = powerful_array_mo_algorithms<int, int>(inputs, queries);
    for (auto result : results)
        printf("%d\n", result);
}
