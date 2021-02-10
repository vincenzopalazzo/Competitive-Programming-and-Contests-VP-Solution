//
// Created by vincent on 9/14/20.

#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include "LazySegmentTree.hpp"

// get better name
template<typename T>
T solve(cpstl::LazySegmentTree<T> &segment_tree, std::vector<T> &index_frogs, T position_mosquito) {
    auto start_range = 1;
    auto end_range = *std::lower_bound(index_frogs.begin(), index_frogs.end(), position_mosquito);
    auto pos_frog = segment_tree.range_query(1, end_range);
    if (end_range == 0 || pos_frog < position_mosquito) {
        return -1; // no mosquito to eat
    }
    int middle_point;
    while (start_range <= end_range) {
        middle_point = (start_range + end_range) / 2;
        pos_frog = segment_tree.range_query(1, middle_point);
        if (pos_frog < pos_frog)
            start_range = middle_point + 1;
        else
            end_range = middle_point - 1;
    }
    return start_range;
}

template<typename T, typename R>
void mosquitoes_eaten(std::vector<Frog> &frogs, std::vector<Mosquito> &mosquitoes) {
    std::sort(frogs.begin(), frogs.end());
    // We need to do remapping and store a vector if position
    // because the upperboudn is a little bit complex with the personal structure
    // https://stackoverflow.com/questions/44245803/using-lower-bound-or-upper-bound-on-structure-in-c
    std::vector<T> index_frogs;
    for (auto frog : frogs)
        index_frogs.emplace_back(frog.position);
    auto segment_tree = cpstl::LazySegmentTree<T>(frogs);
    std::multiset<std::pair<T, R>> solutions;
    for (auto mosquito : mosquitoes) {
        auto frog_pos = solve(segment_tree, index_frogs, mosquito.position);
        if (frog_pos == -1) {
            solutions.insert(std::pair<T, R>(mosquito.position, mosquito.dimension));
        } else {
            auto frog = frogs[frog_pos];
            frog.mosquito_eaten++;
            frog.length_tongue += mosquito.dimension;
            segment_tree.update_range(1, frog_pos, mosquito.dimension);
            auto new_length_tongue = frog.length_tongue + frog.position;
            while (!solutions.empty()) {
                auto new_mosquito = solutions.lower_bound(std::pair<T, R>(frog.position, 0));
                if (new_mosquito == solutions.end() || new_mosquito->first > new_length_tongue)
                    break;
                new_length_tongue += new_mosquito->second;
                frog.mosquito_eaten++;
                frog.length_tongue += mosquito.dimension;
                segment_tree.update_range(1, frog_pos, mosquito.dimension);
                solutions.erase(new_mosquito);
            }
        }
    }
}
