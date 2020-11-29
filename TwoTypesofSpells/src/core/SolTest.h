//
// Created by vincent on 9/14/20.
//
#ifndef SPYCBLOCK_SOLTEST_H
#define SPYCBLOCK_SOLTEST_H
#include <vector>
#include <set>

struct Comparator {
    bool operator()(const std::pair<int, int>& l, const std::pair<int, int>& r) const {
        //Compare canonical forms of l and r.
        return l.second < r.second;
    }
};

template <typename T, typename R>
R calculate_max_damage(std::set<std::pair<int, T>, Comparator> const &inputs);

template <typename T, typename R>
R calculate_max_damage_two(std::vector<pair < int, uint64_t>> inputs);

#endif //SPYCBLOCK_SOLTEST_H