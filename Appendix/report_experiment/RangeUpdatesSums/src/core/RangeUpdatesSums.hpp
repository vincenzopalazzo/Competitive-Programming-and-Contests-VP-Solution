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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */
#include <cstdlib>
#include <string>
#include <vector>

#include "../test/Utils.hpp"
#include "LazySegmentTree.hpp"

const cpstl::Log LOG(true);

template <typename T>
struct Query {
  T value;
  std::size_t start;
  std::size_t end;
  /**
   * Valid Type 1 to 3.
   * 1 -> Increase each value in range [a,b] by x.
   * 2 -> Set each value in range [a,b] to x.
   * 3 -> Calculate the sum of values in range [a,b].
   */
  uint type;

  Query(T value, std::size_t start, std::size_t anEnd, uint type)
      : value(value), start(start), end(anEnd), type(type) {}
  Query(std::size_t start, std::size_t anEnd)
      : start(start), end(anEnd), type(3) {}
};

template <typename T, typename R>
static std::vector<R> range_sum_lazy_segment_tree(
    std::vector<T> &inputs, std::vector<Query<T>> const &queries) {
  auto segment_tree = cpstl::LazySegmentTree<R>(inputs);
  std::vector<R> result;
  result.reserve(queries.size());
  for (auto query : queries) {
    cpstl::cp_log(LOG, "Query (" + std::to_string(query.start) + ", " +
                           std::to_string(query.end) + ")");
    switch (query.type) {
      case 1:
        cpstl::cp_log(LOG, "+ " + std::to_string(query.value));
        segment_tree.increase_range(query.start - 1, query.end - 1,
                                    query.value);
        break;
      case 2:
        cpstl::cp_log(LOG, "override with " + std::to_string(query.value));
        segment_tree.update_range(query.start - 1, query.end - 1, query.value);
        break;
      case 3:
        auto value = segment_tree.range_query(query.start - 1, query.end - 1);
        cpstl::cp_log(LOG, "Value in the range Q(" +
                               std::to_string(query.start) + ", " +
                               std::to_string(query.end) + ") -> " +
                               std::to_string(value));
        result.emplace_back(value);
        break;
    }
  }
  return result;
}
