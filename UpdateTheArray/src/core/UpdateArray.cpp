//
// Created by vincent on 9/14/20.
//
#include "UpdateArray.h"
#include <iostream>

using namespace std;

template <typename T>
vector<T> update_array(std::vector<update<T>> const &updates, std::vector<int> const &queries, int size_array)
{
    vector<T> result;
    result.reserve(queries.size());
    vector<T> input = vector<int>(size_array);

    for (auto update : updates) {
        auto start = update.start;
        auto end = update.end;
        while (start <= end) {
            input[start] += update.value;
            start++;
        }
    }

    for (auto query : queries) {
        auto res = input[query];
        result.push_back(res);
    }
    return result;
}

template vector<int> update_array(std::vector<update<int>> const &updates, std::vector<int> const &queries, int size_array);
