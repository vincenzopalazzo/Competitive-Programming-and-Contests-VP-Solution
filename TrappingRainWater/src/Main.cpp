//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include <cstdlib>
#include "core/TrappingRainWater.h"

using namespace std;

int main(int argc, char* argv[]){
    std::vector<int> inputs = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << "Water trapped: " << trapping_water_one_sol(inputs) << "\n";

    inputs = {7, 4, 0, 9};
    std::cout << "Water trapped: " << trapping_water_one_sol(inputs) << "\n";

    // 8 8 2 4 5 5 1
    inputs = {8, 8, 2, 4, 5, 5, 1};
    std::cout << "Water trapped: " << trapping_water_one_sol(inputs) << "\n";

    std::cout << "--------------- OPTIMIZZED ---------------------\n";
    inputs = {7, 4, 0, 9};
    std::cout << "Water trapped: " << trapping_water_optimize_sol(inputs) << "\n";

    // 8 8 2 4 5 5 1
    inputs = {8, 8, 2, 4, 5, 5, 1};
    std::cout << "Water trapped: " << trapping_water_optimize_sol(inputs) << "\n";

    // 1 1 5 2 7 6 1 4 2 3
    inputs = {1, 1, 5, 2, 7, 6, 1, 4, 2, 3};
    std::cout << "Water trapped: " << trapping_water_optimize_sol(inputs) << "\n";
    return EXIT_SUCCESS;
}
