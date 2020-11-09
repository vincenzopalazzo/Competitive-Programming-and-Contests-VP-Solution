//
// Created by vincent on 9/14/20.
//
#include <cstdlib>
#include <vector>
#include <fstream>
#include "../core/CountTriples.h"
#include "../Utils.cpp"
#include "TestTool.cpp"

using namespace std;
using namespace cpstl;

void TEST_TRIVIAL()
{
    vector<int> inputs = {1, 2, 3, 4, 1};
    int triples = count_triples_trivial<int, int>(inputs);
    assert_equal("Trivial", 4, triples);
}

int main()
{
    TEST_TRIVIAL();

    return EXIT_SUCCESS;
}