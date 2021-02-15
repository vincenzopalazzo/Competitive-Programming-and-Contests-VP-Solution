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
#include <map>
#include <numeric>

namespace sol {
    template <typename T>
    struct pair {
        T first;
        T second;
    };
}


template<typename T>
std::vector<T> find_num_successor_elem(const std::string &input, const std::vector<std::pair<T, T>> &queries)
{
    const char *c_string = input.data();
    std::vector<int> preprocess;
    preprocess.reserve(input.size());

    preprocess.push_back(0);
    for (std::size_t i = 0; i < input.size() - 1; i++) {
        if (c_string[i] == c_string[i + 1]) {
            preprocess.push_back(1);
            continue;
        }
        preprocess.push_back(0);
    }

    std::vector<T> result;
    result.reserve(queries.size());
    int res[input.size()];
    std::partial_sum(preprocess.begin(), preprocess.end(), res);
    for (size_t i = 0; i < queries.size(); i++) {
        auto query = queries.at(i);
        int val = res[query.second - 1] - res[query.first - 1];
        result.push_back(val);
    }
    return result;
}

template<typename T>
T *find_num_successor_elem_native(const std::string &input, const sol::pair<T> queries[], int size_query)
{
    const char *c_string = input.data();
    int precompute[input.size()];
    precompute[0] = 0;
    for (int i = 0; i < input.size() - 1; i++) {
        if (c_string[i] == c_string[i + 1]) {
            precompute[i + 1] = 1;
        } else {
            precompute[i + 1] = 0;
        }
    }

    int res[input.size()];
    std::partial_sum(precompute, precompute + input.size() + 1, res);
    int *result = new int[size_query];
    for (int i = 0; i < size_query; i++) {
        auto query = queries[i];
        printf("VAL (%d, %d)\n", res[query.second - 1], res[query.first - 1]);
        result[i] = res[query.second - 1] - res[query.first - 1];
        printf("RES %d\n", res[query.second - 1] - res[query.first - 1]);
    }
    return result;
}