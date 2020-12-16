//
// Created by vincent on 9/14/20.
//
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "../core/SolTest.h"
#include "TestTool.cpp"

using namespace std;
using namespace cpstl;

void TEST_CASE_ONE_LIST()
{
    vector<pair<int, int>> inputs;
    inputs.emplace_back(pair<int, int>(1, 5));
    inputs.emplace_back(pair<int, int>(0, 10));
    inputs.emplace_back(pair<int, int>(1, -5));
    inputs.emplace_back(pair<int, int>(0, 5));
    inputs.emplace_back(pair<int, int>(1, 11));
    inputs.emplace_back(pair<int, int>(0, -10));
    vector<int> result;
    vector<pair<int, int>> spells;
    result.reserve(inputs.size());
    for (auto spell : inputs) {
        cout << "Insert: (" << spell.first << ", " << spell.second << ")\n";
        if (spell.second > 0) {
            spells.push_back(spell);
        } else {
            auto val = std::pair<int, int>(spell.first, std::abs(spell.second));
            auto pos = std::find(spells.begin(), spells.end(), val);
            spells.erase(pos);
        }
        auto damage = calculate_max_damage<int, int>(spells);
        cout << "Damage: " << damage << "\n";
        result.push_back(damage);
    }
    assert_equal("TEST_CASE_ONE_LIST", {5, 25, 10, 15, 36, 21}, result);
}

int main()
{
    TEST_CASE_ONE_LIST();

    return EXIT_SUCCESS;
}
