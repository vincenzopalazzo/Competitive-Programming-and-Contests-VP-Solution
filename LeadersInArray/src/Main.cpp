//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include <cstdlib>
#include <vector>
#include "core/LeadersInArray.h"

int main(int argc, char* argv[]){
    std::vector<int> inputs = {16, 17, 4, 3, 5, 2};
    std::deque<int> result = get_leaders_from_array_counting_sort_custom(inputs);
    std::cout << "Inputs: ";
    for (auto elem : inputs) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::cout << "Leaders: ";
    for (auto elem : result) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}