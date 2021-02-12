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

template<typename V>
struct Tree {
    V left = 0;
    V right = 0;
    V key = 0;
};

template<typename V, typename C>
struct Query {
    V vertex;
    C kth_color;
    V from; // set value after eulero tour over the tree
    V to; // set value after eulero tour over the tree
    std::size_t size_block;
    std::size_t index_query;

    Query(V vertex, C kthColor, size_t sizeBlock, std::size_t index_query) :
            vertex(vertex - 1), kth_color(kthColor), size_block(sizeBlock), index_query(index_query) {}
};

template<typename T>
static void eulero_tour_remapping(std::vector<T> const &inputs, std::vector<std::vector<T>> &edges,
                                  std::vector<Tree<T>> &remapping,
                                  T current, T parent);

template<typename T>
static void remapping_query_after_eulero_tour(std::vector<Tree<T>> &eulero_visit,
                                              std::vector<Query<T, T>> &queries);

template<typename T>
static bool compare(Query<T, T> const &query_a, Query<T, T> const &query_b) {
    auto left_block = query_a.from / query_a.size_block;
    auto right_block = query_b.from / query_b.size_block;
    if (left_block != right_block)
        return left_block < right_block;
    return query_a.to < query_b.to;
}

template<typename T, typename R>
static void increment(std::vector<Tree<T>> const &input, std::vector<T> &counter, std::vector<R> &answer, std::size_t position) {
    auto to_pos = input[position].key;
    counter[to_pos]++;
    auto count = counter[to_pos];
    if (count >= answer.size()) answer.push_back(0);
    answer[count]++;
}

template<typename T, typename R>
static void decrement(std::vector<Tree<T>> const &input,std::vector<T> &counter, std::vector<R> &answer, std::size_t position) {
    auto to_pos = input[position].key;
    auto count = counter[to_pos];
    answer[count]--;
    counter[to_pos]--;
    if (answer.back() == 0) answer.pop_back();
}

template<typename T, typename R>
static std::vector<R>
numbers_of_vertices_with_color(std::vector<T> &inputs, std::vector<std::vector<T>> &edges,
                               std::vector<Query<T, T>> &queries) {
    std::vector<Tree<T>> eulero_visit;
    eulero_visit.reserve(inputs.size());
    eulero_tour_remapping<T>(inputs, edges, eulero_visit, 0, -1); // Start from 0 and the parent is null (-1)
    remapping_query_after_eulero_tour(eulero_visit, queries);

    std::stable_sort(queries.begin(), queries.end(), compare<T>);

    auto max_color_val = *std::max_element(inputs.begin(), inputs.end());

    std::vector<R> result(queries.size(), 0);
    std::vector<T> counter(1 + max_color_val, 0);
    std::vector<R> suffix;
    suffix.reserve(max_color_val);
    suffix.push_back(max_color_val);
    T current_left = 0;
    T current_right = -1;
    for (auto query : queries) {
        auto left_point = query.from;
        auto right_point = query.to;

        while (current_right < right_point) {
            increment(eulero_visit, counter, suffix, ++current_right);
        }

        while (current_left < left_point) {
            decrement(eulero_visit, counter, suffix, current_left++);
        }

        while (current_left > left_point) {
            increment(eulero_visit, counter, suffix, --current_left);
        }

        while (current_right > right_point) {
            decrement(eulero_visit, counter, suffix, current_right--);
        }
        cpstl::cp_log(LOG, "KTh: " + std::to_string(query.kth_color));
        cpstl::cp_log(LOG, suffix);
        auto r = query.kth_color < suffix.size() ? suffix[query.kth_color] : 0;
        cpstl::cp_log(LOG, "Suffix: " + std::to_string(r));
        result[query.index_query] = r;
    }
    return result;
}

template<typename T>
static void eulero_tour_remapping(std::vector<T> &inputs, std::vector<std::vector<T>> &edges,
                                  std::vector<Tree<T>> &remapping,
                                  T current, T parent) {
    Tree<T> node;
    remapping.emplace_back(node);
    Tree<T> &ref = remapping.back();
    ref.key = inputs[current];
    assert(ref.key >= 0);
    ref.left = remapping.size() - 1;
    for (auto const &edge : edges[current]) {
        if (edge == parent) continue;
        eulero_tour_remapping(inputs, edges, remapping, edge, current);
    }
    ref.right = remapping.size() - 1;
}

template<typename T>
static void
remapping_query_after_eulero_tour(std::vector<Tree<T>> &eulero_visit, std::vector<Query<T, T>> &queries) {
    for (auto &query : queries) {
        assert(eulero_visit[query.vertex].key >= 0);
        query.from = eulero_visit[query.vertex].left;
        query.to = eulero_visit[query.vertex].right;
    }
}
