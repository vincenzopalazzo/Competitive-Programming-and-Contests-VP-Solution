//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include <cstdlib>
#include "core/InvertionCounting.h"
#include <vector>
#include <cassert>

using namespace std;

int main(int argc, char* argv[]){

    vector<int> input = {5, 2, 3, 8, 6, 1};
    int invertions = count_inversion_merge_sort(input);
    cout << invertions << "\n";
    assert(invertions == 5);

    input = {3, 3, 1, 2};
    invertions = count_inversion_merge_sort(input);
    cout << invertions << "\n";
    assert(invertions == 2);

    return EXIT_SUCCESS;
}