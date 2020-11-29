//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include "RangeMinimumQuery.hpp"

template <typename T>
std::vector<T> range_minimum_query_naive(std::vector<T> const &inputs, std::vector<Query<T>> &queries)
{
    std::vector<T> results;
    results.reserve(queries.size());
    for (auto &query : queries) {
        T minimum = INT32_MAX;
        for (std::size_t i = query.start; i <= query.end; i++) {
            if (inputs[i] < minimum) {
                minimum = inputs[i];
            }
        }
        results.push_back(minimum);
    }
    return results;
}

template <typename T>
std::vector<T> range_minimum_query_segment_tree(cpstl::SegmentTree<T> &segmentTree, std::vector<Query<T>> &queries)
{
    std::vector<T> results;
    results.reserve(queries.size());
    for (auto &query : queries) {
        if (query.update) {
            segmentTree.update(query.start - 1, query.end);
            continue;
        }
        auto res = segmentTree.range_query(query.start - 1, query.end - 1);
        results.push_back(segmentTree.value_at(res));
    }
    return results;
}

template std::vector<int> range_minimum_query_naive(std::vector<int> const &inputs, std::vector<Query<int>> &queries);
template std::vector<int> range_minimum_query_segment_tree(cpstl::SegmentTree<int> &segmentTree, std::vector<Query<int>> &queries);