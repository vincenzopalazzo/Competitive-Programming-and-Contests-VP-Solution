//
// Created by vincent on 9/14/20.
//
#ifndef SPYCBLOCK_SOLTEST_H
#define SPYCBLOCK_SOLTEST_H

#include <vector>

template <typename T>
struct Query {
    size_t start;
    size_t end;
    T value;

    Query(size_t start, size_t anEnd, T value) : start(start), end(anEnd), value(value) {}
};

template <typename T, typename R>
std::vector<R> get_numbers_of_smaller_number(std::vector<T> &inputs, std::vector<Query<T>> queries);

#endif //SPYCBLOCK_SOLTEST_H
