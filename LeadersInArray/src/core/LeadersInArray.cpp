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
#include "LeadersInArray.h"
#include <deque>

using namespace std;

std::deque<int> get_leaders_from_array_counting_sort_custom(const std::vector<int> &inputs)
{
    deque<int> result;
    int max_right_value = inputs.at(inputs.size() - 1);
    max_right_value = max_right_value;
    result.push_front(max_right_value);
    for (int i = inputs.size() - 2; i >= 0; i--) {
       int actual_val = inputs.at(i);
       if (actual_val >= max_right_value) {
           max_right_value = actual_val;
           result.push_front(max_right_value);
       }
    }
    return result;
}
