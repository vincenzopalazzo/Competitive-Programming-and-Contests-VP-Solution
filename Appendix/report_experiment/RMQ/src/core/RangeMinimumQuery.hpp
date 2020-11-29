//
// Created by vincent on 9/14/20.
//
#ifndef SPYCBLOCK_SOLTEST_H
#define SPYCBLOCK_SOLTEST_H
#include <cstdlib>
#include <string>
#include <vector>
#include "SegmentTree.h"
#include "../test/Utils.hpp"

const cpstl::Log LOG(true);

template <typename T>
struct Query {
    bool update;
    T start;
    T end;
    Query(bool type, T start, T anEnd) : update(type), start(start), end(anEnd) {}
};

template <typename T>
std::vector<T> range_minimum_query_naive(std::vector<T> const &inputs, std::vector<Query<T>> &queries);

template <typename T>
std::vector<T> range_minimum_query_segment_tree(cpstl::SegmentTree<T> &segmentTree, std::vector<Query<T>> &queries);

#endif //SPYCBLOCK_SOLTEST_H
