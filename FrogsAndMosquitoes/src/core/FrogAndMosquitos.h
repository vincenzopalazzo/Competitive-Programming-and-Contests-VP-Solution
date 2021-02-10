//
// Created by vincent on 9/14/20.

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "SegmentTree.hpp"

typedef std::make_signed<std::size_t>::type ssize_t;

// get better name
template<typename T>
ssize_t solve(cpstl::SegmentTree<T> &segment_tree, std::vector<T> &index_frogs, std::size_t position_mosquito) {
    std::size_t start_range = 0;
    auto it_end_range = std::upper_bound(index_frogs.begin(), index_frogs.end(), position_mosquito);
    auto end_range = it_end_range - index_frogs.begin() - 1;
    auto pos_frog = segment_tree.range_query(start_range, end_range);
    if (it_end_range == index_frogs.end() || pos_frog < position_mosquito) {
        return -1; // no mosquito to eat
    }
    std::size_t middle_point;
    while (start_range < end_range) {
        middle_point = (start_range + end_range) / 2;
        pos_frog = segment_tree.range_query(0, middle_point);
        if (start_range < pos_frog)
            start_range = middle_point + 1;
        else
            end_range = middle_point - 1;
    }
    return start_range;
}

template<typename T, typename R>
void mosquitoes_eaten(std::vector<Frog<T>> &frogs, std::vector<Mosquito<T>> &mosquitoes) {
    std::sort(frogs.begin(), frogs.end());
    // We need to do remapping and store a vector if position
    // because the upperbound is a little bit complex with the personal structure
    // https://stackoverflow.com/questions/44245803/using-lower-bound-or-upper-bound-on-structure-in-c
    std::vector<T> index_frogs;
    index_frogs.reserve(frogs.size());
    for (auto frog : frogs)
        index_frogs.emplace_back(frog.position);
    auto segment_tree = cpstl::SegmentTree<T>(frogs);
    std::multiset<std::pair<T, R>> solutions;
    for (auto mosquito : mosquitoes) {
        auto frog_pos = solve(segment_tree, index_frogs, mosquito.position);
        if (frog_pos == -1) {
            solutions.insert(std::pair<T, R>(mosquito.position, mosquito.dimension));
        } else {
            auto frog = &frogs.at(frog_pos); // the position of the fron is in the position (frog_pos - 1) - 1
            frog->mosquito_eaten++;
            frog->length_tongue += mosquito.dimension;
            segment_tree.update(frog_pos, mosquito.dimension);
            auto new_length_tongue = frog->length_tongue + frog->position;
            while (!solutions.empty()) {
                auto new_mosquito = solutions.lower_bound(std::pair<T, R>(frog->position, 0));
                if (new_mosquito == solutions.end() || new_mosquito->first > new_length_tongue) {
                    break;
                }
                new_length_tongue += new_mosquito->second;
                frog->mosquito_eaten++;
                frog->length_tongue += mosquito.dimension;
                segment_tree.update(frog_pos, mosquito.dimension);
                solutions.erase(new_mosquito);
            }
        }
    }
    std::sort(frogs.begin(), frogs.end(), [](auto frog_a, auto frog_b){
        return frog_a.input_pos < frog_b.input_pos;
    });
}
