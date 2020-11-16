//
// Created by vincent on 9/14/20.
//
#include <cstdlib>
#include <vector>
#include "../core/FindingTeamMember.h"
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