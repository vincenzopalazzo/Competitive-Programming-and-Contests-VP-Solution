//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include "core/Tower.h"

int main()
{
    std::vector<int> inputs = {6, 5, 6, 7};
    std::pair<int, int> result = calculate_number_of_tower(inputs);
    std::cout << result.first << " " << result.second << std::endl;

    inputs = {47, 30, 94, 41, 45, 20, 96, 51, 110, 129, 24, 116, 9, 47, 32, 82, 105, 114, 116, 75, 154, 151, 70, 42, 162};
    result = calculate_number_of_tower(inputs);
    std::cout << result.first << " " << result.second << std::endl;

    return EXIT_SUCCESS;
}
