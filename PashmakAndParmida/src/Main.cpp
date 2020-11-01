//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include <cstdlib>
#include <cassert>
#include "core/PashmakAndParmida.h"

using namespace std;

int main()
{
    std::cout << "============== TEST CASE 1 ==============" << "\n";
    vector<int> inputs = {1, 2, 1, 1, 2, 2, 1};

    int result = pair_indices<int>(inputs);
    cout << result << "\n";
    assert(result == 8);

    std::cout << "============== TEST CASE 2 ==============" << "\n";

    inputs = {1, 1, 1};
    result = pair_indices<int>(inputs);
    cout << result << "\n";
    assert(result == 1);

    std::cout << "============== TEST CASE 3 ==============" << "\n";
    inputs = {1, 2, 3, 4, 5};
    result = pair_indices<int>(inputs);
    cout << result << "\n";
    assert(result == 0);

    std::cout << "=========== TEST CASES PASSED ==========" << "\n";
    return EXIT_SUCCESS;
}