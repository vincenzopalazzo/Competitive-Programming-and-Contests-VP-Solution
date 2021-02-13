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
#include "../core/FindingTeamMember.hpp"
#include "../Utils.cpp"
#include "TestTool.cpp"

using namespace std;
using namespace cpstl;

void TEST_CASE_ONE()
{
    int number_teams = 2;
    vector<Team<int>> inputs;
    inputs.emplace_back(1, 0, 6);
    inputs.emplace_back(2, 0, 1);
    inputs.emplace_back(2, 1, 2);
    inputs.emplace_back(3, 0, 3);
    inputs.emplace_back(3, 1, 4);
    inputs.emplace_back(3, 2, 5);
    auto teams = finding_team_members<int, int>(inputs, number_teams);
    assert_equal("TEST_CASE_ONE", {2, 1, 4, 3}, teams);
}

void TEST_CASE_TWO()
{
    int number_teams = 3;
    vector<Team<int64_t>> inputs;
    inputs.emplace_back(1, 0, 487060);
    inputs.emplace_back(2, 0, 3831);
    inputs.emplace_back(2, 1, 161856);
    inputs.emplace_back(3, 0, 845957);
    inputs.emplace_back(3, 1, 794650);
    inputs.emplace_back(3, 2, 976977);
    inputs.emplace_back(4, 0, 83847);
    inputs.emplace_back(4, 1, 50566);
    inputs.emplace_back(4, 2, 691206);
    inputs.emplace_back(4, 3, 498447);
    inputs.emplace_back(5, 0, 698377);
    inputs.emplace_back(5, 1, 156232);
    inputs.emplace_back(5, 4, 59015);
    inputs.emplace_back(5, 3, 382455);
    inputs.emplace_back(5, 4, 626960);
    auto teams = finding_team_members<int64_t, int>(inputs, number_teams);
    assert_equal("TEST_CASE_TWO", {6, 5, 4, 3, 2, 1}, teams);
}


int main()
{
    TEST_CASE_ONE();
    TEST_CASE_TWO();

    return EXIT_SUCCESS;
}