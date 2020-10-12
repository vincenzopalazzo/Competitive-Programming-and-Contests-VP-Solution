//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include <cstdlib>
#include "core/LittleGirlAndMaximumSum.h"

using namespace std;

int main(int argc, char* argv[]){

    vector<int> inputs = {5, 2, 4, 1, 3};
    vector<pair<int, int>> queries;
    queries.emplace_back(1, 5);
    queries.emplace_back(2, 3);
    queries.emplace_back(2, 3);

    cout << "Max sum " << max_sum_of_queries(inputs, queries) << "\n";

    return EXIT_SUCCESS;
}