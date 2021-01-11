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
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
static T get_alternative_score(std::string const &binary_score)
{
    T result = 0;
    char const *c_string = binary_score.c_str();
    for (int i = 1; i < binary_score.size(); i++) {
        if (c_string[i] == c_string[i - 1])
            result++;
    }
    result = binary_score.size() - result;
    return std::min(result + 2, static_cast<T>(binary_score.size()));
}

int main() {
    int N;
    std::string binary_string;
    cin >> N;
    cin >> binary_string;
    auto result = get_alternative_score<int>(binary_string);
    printf("%d\n", result);
}
