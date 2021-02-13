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
#include <string>
#include <vector>
#include <algorithm>

template <typename T>
struct Team {
    size_t i;
    size_t j;
    T strength;

    Team(size_t i, size_t j, T strength) : i(i), j(j), strength(strength) {}
};

template <typename T, typename R>
std::vector<R> finding_team_members(std::vector<Team<T>> &inputs, R teams_to_be_formed)
{
    std::sort(inputs.begin(), inputs.end(), [](Team<T> a, Team<T> b){
        return a.strength > b.strength;
    });

    //Store the value of team mate
    std::vector<R> result(2 * teams_to_be_formed);
    for (auto team : inputs) {
        if(result[team.i] == 0 and result[team.j] == 0) {
            // +1, 0 is reserved to "no assigment yet"
            result[team.i] = team.j + 1;
            result[team.j] = team.i + 1;
        }
    }

    return result;
}