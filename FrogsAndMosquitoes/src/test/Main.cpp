//
// Created by vincent on 9/14/20.
//
#include <cstdlib>
#include <vector>
#include "../core/FrogAndMosquitos.h"
#include "Utils.hpp"
#include "TestTool.hpp"

using namespace std;

void TEST_CASE_ONE() {
    std::vector<Frog<int>> frogs;
    frogs.emplace_back(10, 2, 0);
    frogs.emplace_back(15, 0, 1);
    frogs.emplace_back(6, 1, 2);
    frogs.emplace_back(0, 1, 3);

    std::vector<Mosquito<int>> mosquitoes;
    mosquitoes.emplace_back(110, 10);
    mosquitoes.emplace_back(1, 1);
    mosquitoes.emplace_back(6, 0);
    mosquitoes.emplace_back(15, 10);
    mosquitoes.emplace_back(14, 100);
    mosquitoes.emplace_back(12, 2);

    mosquitoes_eaten<int, int>(frogs, mosquitoes);
    std::vector<std::pair<int, int>> results;
    for (auto &frog: frogs) {
        results.emplace_back(frog.mosquito_eaten, frog.length_tongue);
    }
    cpstl::assert_equal<int, int>("TEST_CASE_ONE",
                                  {{3, 114},
                                   {1, 10},
                                   {1, 1},
                                   {1, 2}}, results);
}

void TEST_CASE_TWO() {
    std::vector<Frog<int>> frogs;
    frogs.emplace_back(10, 2, 0);

    std::vector<Mosquito<int>> mosquitoes;
    mosquitoes.emplace_back(20, 2);
    mosquitoes.emplace_back(12, 1);

    mosquitoes_eaten<int, int>(frogs, mosquitoes);
    std::vector<std::pair<int, int>> results;
    for (auto &frog: frogs) {
        results.emplace_back(frog.mosquito_eaten, frog.length_tongue);
    }
    cpstl::assert_equal<int, int>("TEST_CASE_TWO",
                                  {{1, 3}}, results);
}

void TEST_CASE_THREE() {
    std::vector<Frog<int>> frogs = {
            {33,  2,   0},
            {922, 34,  1},
            {480, 105, 2},
            {844, 5,   3},
            {739, 39,  4},
            {325, 20,  5},
            {999, 88,  6},
            {462, 104, 7},
            {225, 5,   8},
            {93,  4,   9}
    };

    std::vector<Mosquito<int>> mosquitoes = {
            {13,  15},
            {323, 9},
            {152, 20},
            {785, 11},
            {512, 4},
            {859, 8},
            {327, 14},
            {818, 9},
            {794, 13},
            {99,  20}
    };

    mosquitoes_eaten<int, int>(frogs, mosquitoes);
    std::vector<std::pair<int, int>> results;
    for (auto &frog: frogs) {
        cout << frog.mosquito_eaten << ":" << frog.length_tongue << "\n";
        results.emplace_back(frog.mosquito_eaten, frog.length_tongue);
    }
    cpstl::assert_equal<int, int>("TEST_CASE_THREE", {
            {0, 2},
            {0, 34},
            {0, 105},
            {0, 5},
            {0, 39},
            {1, 34},
            {0, 88},
            {1, 108},
            {0, 5},
            {0, 4},
    }, results);
}

int main() {
    TEST_CASE_ONE();
    TEST_CASE_TWO();
    TEST_CASE_THREE();
    return EXIT_SUCCESS;
}
