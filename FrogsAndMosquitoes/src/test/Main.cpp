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
    for (auto &frog: frogs){
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
    for (auto &frog: frogs){
        results.emplace_back(frog.mosquito_eaten, frog.length_tongue);
    }
    cpstl::assert_equal<int, int>("TEST_CASE_TWO",
                                  {{1, 3}}, results);
}

int main() {
    TEST_CASE_ONE();
    TEST_CASE_TWO();
    return EXIT_SUCCESS;
}
