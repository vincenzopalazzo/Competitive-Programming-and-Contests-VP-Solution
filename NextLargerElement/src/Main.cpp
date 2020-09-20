//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include <cstdlib>
#include <vector>
#include "core/NextLargerElement.h"

int main(int argc, char* argv[]){
    std::vector<int> inputs = {1, 3, 2, 4};
    std::vector<int> result = calc_next_larger_elem_naive(inputs);
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
    return EXIT_SUCCESS;
}