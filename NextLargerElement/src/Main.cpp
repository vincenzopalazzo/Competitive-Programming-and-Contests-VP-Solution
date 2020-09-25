//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include <cstdlib>
#include <vector>
#include "core/NextLargerElement.h"

int main(int argc, char* argv[]){
    std::vector<int64_t> inputs = {1, 3, 2, 4};
    std::cout << "---------- NAIVE SOL ---------" << std::endl;
    std::vector<int64_t> result = calc_next_larger_elem_naive(inputs);
    std::cout << "Input ";
    for (auto elem : inputs) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    std::cout << "Result ";
    for (auto elem : result) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    std::cout << "------------- STACK SOLUTION ---------------" << std::endl;
    std::cout << "Input ";
    for (auto elem : inputs) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    std::vector<std::pair<int, int64_t>> map = calc_next_larger_elem_stack(inputs);
    std::cout << "Result ";
    int64_t res[map.size()];
    for (auto elem : map) {
        res[elem.first] = elem.second;
    }
    for (int i = 0; i < map.size(); i++) {
        std::cout << res[i] << " ";
    }
    std::cout << "\n";
    return EXIT_SUCCESS;
}
