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
#include <algorithm>

#include <vector>

using namespace std;

namespace cpstl {
/**
 * Search algorithm's C++ implementation
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */
template <class T, typename R>
class Search {
 protected:
  static R _binary_search(std::vector<T> const &inputs, T key,
                          std::size_t start, std::size_t end) {
    if (start > end) return -1;
    // We go to te middle of algorithm
    auto middle_pos = start + (end - start) / 2;
    if (inputs[middle_pos] > key) {
      // sub array [start, middle_pos]
      return _binary_search(inputs, key, start, middle_pos - 1);
    } else if (inputs[middle_pos] < key) {
      // sub array [middle_pos - end]
      return _binary_search(inputs, key, middle_pos + 1, end);
    }
    return middle_pos;
  }

 public:
  static R binary_search(std::vector<T> const &inputs, T key) {
    return _binary_search(inputs, key, 0, inputs.size() - 1);
  }

  static R binary_search(std::vector<T> const &inputs, T key,
                         std::size_t start, std::size_t end) {
    return _binary_search(inputs, key, start, end);
  }

  static R exponential_search(std::vector<T> const &inputs, T key) {
    if (inputs[0] == key) return 0;
    R size_sub_array = 1;
    while (size_sub_array < inputs.size() && inputs[size_sub_array] < key) {
      size_sub_array *= 2;
    }
    R start = size_sub_array;
    R end = std::min(size_sub_array, static_cast<R>(inputs.size() - 1));
    return _binary_search(inputs, key, start, end);
  }
};
};  // namespace cpstl


template<typename T>
std::pair<T, int> calculate_number_of_tower(std::vector<T> &inputs)
{
    std::pair<T, int> result;
    int max_height = 1;
    int actual_max = 1;
    int number_tower = 0;

    std::sort(inputs.begin(), inputs.end());
    for (int i = 0; i < inputs.size(); i++) {
        int pos = cpstl::Search<int, int>::binary_search(inputs, inputs.at(i), i + 1, inputs.size() - 1);
        if (pos != -1) {
            actual_max++;
        } else {
            if (actual_max > max_height) max_height = actual_max;
            actual_max = 1;
            number_tower++;
        }
    }

    result.first = max_height;
    result.second = number_tower;
    return result;
}

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(int i = 0; i < n; ++i)
        cin >> sequence[i];
    return sequence;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;
    auto inputs = get_input_sequence<int>(n);

    std::pair<int, int> result = calculate_number_of_tower(inputs);
    std::cout << result.first << " " << result.second << std::endl;

    return 0;
}
