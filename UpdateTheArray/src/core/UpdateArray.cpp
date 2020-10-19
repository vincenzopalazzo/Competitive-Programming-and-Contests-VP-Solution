//
// Created by vincent on 9/14/20.
//
#include "UpdateArray.h"
#include <iostream>
#include "FenwickTree.h"

using namespace std;
using namespace cpstl;

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

template <typename T>
std::vector<T> update_array_binary_index_tree(std::vector<update<T>> const &updates, std::vector<int> const &queries, int size_array)
{
    vector<T> result;
    result.reserve(queries.size());
    auto tree = BTreeIndex<T>(size_array);

    for (auto update : updates) {
        auto start = update.start;
        auto end = update.end;
        tree.update(update.value, start);
        tree.update(-1 * update.value, end + 1);
    }

    for (auto query : queries) {
        auto res = tree.sum(query + 1);
        result.push_back(res);
    }
    return result;
}

template vector<int> update_array(std::vector<update<int>> const &updates, std::vector<int> const &queries, int size_array);
template std::vector<int> update_array_binary_index_tree(std::vector<update<int>> const &updates, std::vector<int> const &queries, int size_array);
