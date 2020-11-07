//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include <cstdlib>
#include <cassert>
#include "core/MissingNumberInArray.h"

using namespace std;

int main()
{
    vector<int> inputs = {1, 2, 3, 4, 5, 7, 8, 9, 10};
    int missing_num = get_missing_number_naive(inputs);
    cout << "Missing number is " << missing_num << "\n";
    assert(missing_num == 6);

    inputs = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    missing_num = get_missing_number_naive(inputs);
    cout << "Missing number is " << missing_num << "\n";
    assert(missing_num == INT32_MAX);
    return EXIT_SUCCESS;
}