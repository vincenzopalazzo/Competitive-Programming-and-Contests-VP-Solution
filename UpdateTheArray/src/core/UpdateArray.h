//
// Created by vincent on 9/14/20.
//
#ifndef SPYCBLOCK_SOLTEST_H
#define SPYCBLOCK_SOLTEST_H
#include <cstdlib>
#include <string>
#include <vector>

template <typename T>
struct update {
    int start;
    int end;
    T value;

    update(int start, int anEnd, T value) : start(start), end(anEnd), value(value) {}
};

template <typename T>
std::vector<T> update_array(std::vector<update<T>> const &updates, std::vector<int> const &queries, int size_array);

#endif //SPYCBLOCK_SOLTEST_H
