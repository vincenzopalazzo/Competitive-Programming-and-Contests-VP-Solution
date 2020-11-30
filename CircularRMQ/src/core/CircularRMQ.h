//
// Created by vincent on 9/14/20.
//
#ifndef SPYCBLOCK_SOLTEST_H
#define SPYCBLOCK_SOLTEST_H

#include "../test/Utils.hpp"
#include "SegmentTree.h"

const cpstl::Log LOG(true);

template <typename T>
struct Query {
    size_t start;
    size_t end;
    T update_val = INT32_MIN;

    Query(size_t start, size_t anEnd) : start(start), end(anEnd) {}
};

template <typename T>
std::vector<T> calculate_minimum_rmq_query(cpstl::SegmentTree<T> &segmentTree, std::vector<Query<T>> const &queries);

#endif //SPYCBLOCK_SOLTEST_H
