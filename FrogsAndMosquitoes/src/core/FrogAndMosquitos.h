//
// Created by vincent on 9/14/20.

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "SegmentTree.hpp"

// get better name
template<typename T>
T solve(cpstl::SegmentTree<T> &segment_tree, std::vector<T> &index_frogs, T position_mosquito) {
    auto start_range = 0;
    std::cout << "Upper bound pos: " << position_mosquito << "\n";
    auto end_range = std::upper_bound(index_frogs.begin(), index_frogs.end(), position_mosquito) - index_frogs.begin();
    auto pos_frog = segment_tree.range_query(start_range, end_range);
    if (end_range == 0 || pos_frog < position_mosquito) {
        return -1; // no mosquito to eat
    }
    int middle_point;
    while (start_range <= end_range) {
        middle_point = (start_range + end_range) / 2;
        pos_frog = segment_tree.range_query(0, middle_point);
        if (start_range < pos_frog)
            start_range = middle_point + 1;
        else
            end_range = middle_point - 1;
    }
    return start_range;
}

template<typename T, typename R> // TODO missed the original position of the Frog
void mosquitoes_eaten(std::vector<Frog> &frogs, std::vector<Mosquito> &mosquitoes) {
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
        std::cout << "Res: solve " << frog_pos << "\n";
        if (frog_pos == -1) {
            solutions.insert(std::pair<T, R>(mosquito.position, mosquito.dimension));
        } else {
            frog_pos -= 1; // the segment tree is indexed by 1 to N;
            auto frog = &frogs.at(frog_pos - 1); // the position of the fron is in the position (frog_pos - 1) - 1
            frog->mosquito_eaten++;
            std::cout << "Mos: " << mosquito.position << " -> pos: " << frog_pos << " eat: " << frog->mosquito_eaten
                      << "\n";
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
                frog->length_tongue += new_mosquito->second;
                std::cout << "Mos: " << new_mosquito->first << " -> pos: " << frog_pos << " eat: " << frog->mosquito_eaten
                          << "\n";
                segment_tree.update(frog_pos, new_mosquito->second);
                solutions.erase(new_mosquito);
            }
        }
    }
    std::sort(frogs.begin(), frogs.end(), [](auto frog_a, auto frog_b){
        return frog_a.input_pos < frog_b.input_pos;
    });
}
