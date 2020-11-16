//
// Created by vincent on 9/14/20.
//
#ifndef SPYCBLOCK_SOLTEST_H
#define SPYCBLOCK_SOLTEST_H
#include <cstdlib>
#include <string>
#include <vector>

template <typename T>
struct Team {
    size_t i;
    size_t j;
    T strength;

    Team(size_t i, size_t j, T strength) : i(i), j(j), strength(strength) {}
};

template <typename T, typename R>
std::vector<R> finding_team_members(std::vector<Team<T>> &inputs, R teams_to_be_formed);

#endif //SPYCBLOCK_SOLTEST_H
