//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include <cstdlib>
#include "core/IlyaAndQueries.h"

using namespace std;

int main(int argc, char* argv[]){

    string input = "......";
    vector<pair<int, int>> queries;
    queries.emplace_back(3, 4);
    queries.emplace_back(2, 3);
    queries.emplace_back(1, 6);
    queries.emplace_back(2, 6);

    auto result = find_num_successor_elem(input, queries);
    for (auto elem : result) {
        printf("%d\n", elem);
    }

    return EXIT_SUCCESS;
}