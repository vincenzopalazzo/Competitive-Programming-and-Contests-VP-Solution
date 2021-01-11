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

static bool is_magic_number(std::string const &input)
{
    for (std::size_t i = 0; i < input.size(); i++) {
        if (input[i] != '1' && input[i] != '4') {
            return false;
        }
    }
    if (input[0] == '4' ) {
        return false;
    }

    if (input.find("444") != input.npos) {
        return false;
    }
    return true;
}

int main() {
    std::string input ;
    cin >> input;
    auto res = is_magic_number(input);
    cout << (res ? "YES" : "NO");
}
