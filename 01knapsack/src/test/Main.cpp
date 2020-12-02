/**
 * Segment tree data structure implementation
 * Copyright (C) 2020  Vincenzo Palazzo vincenzopalazzodev@gmail.com
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
#include "TestTool.hpp"
#include "../core/Knapsack.h"

using namespace std;

void TEST_CASE_ONE_KNAPSACK_TRIVIAL()
{
    vector<Object<int>> objects;
    objects.emplace_back(10, 60);
    objects.emplace_back(20, 100);
    objects.emplace_back(30, 120);
    int capacity = 50;
    auto maximum_elm = sol_knapsack_trivial(capacity, objects, objects.size());

    cpstl::assert_equal("TEST_CASE_ONE_KNAPSACK_TRIVIAL", 220, maximum_elm);
}


int main()
{
    TEST_CASE_ONE_KNAPSACK_TRIVIAL();
    return EXIT_SUCCESS;
}