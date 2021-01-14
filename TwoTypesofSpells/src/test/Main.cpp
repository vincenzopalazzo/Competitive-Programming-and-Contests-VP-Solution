/**
 * Competitive-Programming-and-Contests-VP-Solution a collection of
 * code with an engineering approach to solve the problem.
 * https://github.com/vincenzopalazzo/Competitive-Programming-and-Contests-VP-Solution
 *
 * Copyright (C) 2020-2021  Vincenzo Palazzo vincenzopalazzodev@gmail.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "../core/TwoTypesOfSpells.h"
#include "TestTool.hpp"

using namespace std;
using namespace cpstl;
/*
void TEST_CASE_ONE_LIST()
{
    vector<Spell<int>> inputs;
    inputs.emplace_back(1, 5);
    inputs.emplace_back(0, 10);
    inputs.emplace_back(1, -5);
    inputs.emplace_back(0, 5);
    inputs.emplace_back(1, 11);
    inputs.emplace_back(0, -10);
    vector<int> result;
    vector<pair<int, int>> spells;
    result.reserve(inputs.size());
    for (auto spell : inputs) {
        cout << "Insert: (" << spell.type << ", " << spell.damage << ")\n";
        if (spell.damage > 0) {
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
*/
int main()
{
    //TEST_CASE_ONE_LIST();

    return EXIT_SUCCESS;
}
