//
// Created by vincent on 10/14/20.
//
#include <vector>
#include <algorithm>
#include "SegmentTree.h"
#include "FenwickTree.h"
#include "../test/Utils.hpp"

const cpstl::Log LOG(false);

template<typename T>
static std::vector<T> calculate_frequency_query_by_index(std::vector<std::pair<T, T>> const &queries, std::size_t size_inputs)
{
    std::vector<T> frequencies(size_inputs + 1);
    for (auto query : queries) {
        frequencies[query.first - 1]++;
        frequencies[query.second]--;
    }
    return frequencies;
}

template<typename T>
static T max_sum_of_queries(std::vector<T> &inputs, std::vector<std::pair<T, T>> &queries)
{
    auto frequencies = calculate_frequency_query_by_index(queries, inputs.size());
    // calculate prefix sum
    for (int i = 1; i < frequencies.size(); i++)
        frequencies[i] += frequencies[i - 1];
    std::sort(inputs.begin(), inputs.end());
    std::sort(frequencies.begin(), frequencies.end() - 1);
    cpstl::cp_log(LOG, frequencies);
    // Resolve queries
    T max_sum = 0;
    for (int i = 0; i < inputs.size(); i++) {
        max_sum += frequencies[i] * inputs[i];
    }
    return max_sum;
}

template<typename T>
static T max_sum_of_queries_fenwick_tree(std::vector<T> &inputs, std::vector<std::pair<T, T>> &queries)
{
    auto fenwick_tree = cpstl::BTreeIndex<T>(inputs.size());

    for (auto &query : queries) {
        fenwick_tree.update(1, query.first);
        fenwick_tree.update(-1, query.second + 1);
    }
    std::sort(inputs.begin(), inputs.end());
    std::vector<T> frequencies(inputs.size() + 1, 0);
    for (int i = 1; i <= inputs.size(); i++)
        frequencies[i - 1] = fenwick_tree.sum(i);
    std::sort(frequencies.begin(), frequencies.end() - 1);
    cpstl::cp_log(LOG, frequencies);
    // Resolve queries
    T max_sum = 0;
    for (int i = inputs.size() - 1; i >= 0 ; i--) {
        max_sum += frequencies[i] * inputs[i];
    }
    return max_sum;
}