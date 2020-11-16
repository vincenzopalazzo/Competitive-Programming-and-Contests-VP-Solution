//
// Created by vincent on 9/14/20.
//
#include "FindingTeamMember.h"
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T, typename R>
std::vector<R> finding_team_members(std::vector<Team<T>> &inputs, R teams_to_be_formed)
{
    sort(inputs.begin(), inputs.end(), [](Team<T> a, Team<T> b){
        return a.strength > b.strength;
    });

    //Store the value of team mate
    vector<R> result(2 * teams_to_be_formed);
    for (auto team : inputs) {
        if(result[team.i] == 0 and result[team.j] == 0) {
            // +1, 0 is reserved to "no assigment yet"
            result[team.i] = team.j + 1;
            result[team.j] = team.i + 1;
        }
    }

    return result;
}

template class Team<int>;
template class Team<int64_t>;
template std::vector<int> finding_team_members<int64_t, int>(std::vector<Team<int64_t>> &inputs, int teams_to_be_formed);
template std::vector<int> finding_team_members<int, int>(std::vector<Team<int>> &inputs, int teams_to_be_formed);