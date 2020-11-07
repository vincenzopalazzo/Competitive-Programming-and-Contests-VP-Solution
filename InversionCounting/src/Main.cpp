//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include <cstdlib>
#include "core/InversionCounting.h"
#include <vector>
#include <cassert>

using namespace std;

int main()
{
    vector<int> input = {5, 2, 3, 8, 6, 1};
    int inversions_merge = count_inversion_merge_sort(input);
    cout << "Merge Sort implementation: " << inversions_merge << "\n";
    assert(inversions_merge == 5);

    input = {3, 3, 1, 2};
    inversions_merge = count_inversion_merge_sort(input);
    cout << "Merge Sort implementation: " << inversions_merge << "\n";
    assert(inversions_merge == 2);

    return EXIT_SUCCESS;
}