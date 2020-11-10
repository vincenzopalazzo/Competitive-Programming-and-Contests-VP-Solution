//
// Created by vincent on 9/14/20.
//
#include <cstdlib>
#include <vector>
#include "../core/SmallerValue.h"
#include "../Utils.cpp"
#include "TestTool.cpp"

using namespace std;
using namespace cpstl;

void TEST_TRIVIAL_ONE()
{
    vector<int> inputs = {4, 1, 3, 4, 1};
    vector<Query<int>> queries;
    queries.emplace_back(0, 1, 3);
    queries.emplace_back(0, 4, 3);
    queries.emplace_back(1, 3, 2);
    auto triples = get_numbers_of_smaller_number_trivial<int, int>(inputs, queries);
    assert_equal("trivial_one", {1, 3, 1}, triples);
}

int main()
{
    TEST_TRIVIAL_ONE();

    return EXIT_SUCCESS;
}