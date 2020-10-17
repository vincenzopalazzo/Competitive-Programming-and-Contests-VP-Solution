//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include <cstdlib>
#include <cassert>
#include "core/UpdateArray.h"

using namespace std;

int main()
{
    int size_array = 5;
    vector<update<int>> updates;
    updates.emplace_back(0, 1, 7);
    updates.emplace_back(2, 4, 6);
    updates.emplace_back(1, 3, 2);
    vector<int> queries = {0, 3, 4};

    auto result = update_array(updates, queries, size_array);
    for (auto elem : result)
        cout << elem << "\n";
    assert(result.at(0) == 7);
    assert(result.at(1) == 8);
    assert(result.at(2) == 6);

    cout << "---------- TEST CASE PASSED ------------\n";
    return EXIT_SUCCESS;
}