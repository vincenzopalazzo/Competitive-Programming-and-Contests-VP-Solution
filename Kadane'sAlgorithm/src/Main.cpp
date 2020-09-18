//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include <cstdlib>
#include "core/MaxSumContiguousSubArr.h"

int main(int argc, char* argv[]){
    std::vector<int> inputs = {-1, -2, -3, -4};
    int val = sum_contiguous_sub_arr(inputs);
    std::cout << val;
    return EXIT_SUCCESS;
}