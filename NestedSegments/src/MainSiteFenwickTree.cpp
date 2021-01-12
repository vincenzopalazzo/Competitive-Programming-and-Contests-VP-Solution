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
#include <algorithm>

using namespace std;

namespace cpstl {
/**
 * Binary index tree data structure implementation
 * Copyright (C) 2020  Vincenzo Palazzo vincenzopalazzodev@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
    template<class T>
    class BTreeIndex {
    private:
        std::vector<T> structure;

        inline std::size_t indexing(std::size_t index)
        {
            return index& -index;
        }
    public:
        BTreeIndex(std::vector<T> const &structure)
        {
            this->structure.reserve(structure.size() + 1);
            this->structure[0] = 0;
            for (std::size_t i = 0; i < structure.size(); i++) {
                this->structure[i + 1] = structure[i];
            }

            std::size_t at = 1;
            while (at < this->structure.size()) {
                int at_tree = indexing(at);
                this->structure[at_tree] += this->structure[at];
                at += indexing(at);
            }
        }

        BTreeIndex(std::size_t size)
        {
            structure = std::vector<T>(size + 1);
        }

        inline void update(std::size_t at, T const value)
        {
            while (at < structure.size()) {
                structure[at] += value;
                at += indexing(at);
            }
        }

        inline T sum(std::size_t begin, std::size_t end)
        {
            T sum = 0;
            auto at = end;
            while (at > begin) {
                sum += structure[at];
                at &= at - 1;
            }
            return sum;
        }

        inline T sum(std::size_t end)
        {
            T sum = 0;
            auto at = end;
            while (at > 0) {
                sum += structure[at];
                at &= at -1;
            }
            return sum;
        }
    };
}

template<typename T>
struct Segment {
    T x_coordinate;
    T y_coordinate;
    size_t index;

    Segment(T xCoordinate, T yCoordinate, size_t index) : x_coordinate(xCoordinate), y_coordinate(yCoordinate),
                                                          index(index) {}
};

template<typename T>
static cpstl::BTreeIndex<T> precompute_into_fenwick_tree(std::vector<Segment<T>> &inputs)
{
    //Compute the maximum index inside the segment
    std::vector<T> indexes;
    for (auto &segment : inputs) {
        indexes.push_back(segment.x_coordinate);
        indexes.push_back(segment.y_coordinate);
    }
    std::sort(indexes.begin(), indexes.end());

    for (auto &segment: inputs) {
        // lower_bound get the first element that is smaller that segment.x_coordinate
        auto x_iterator = std::lower_bound(indexes.begin(), indexes.end(), segment.x_coordinate);
        // lower_bound get the first element that is smaller that segment.y_coordinate
        auto y_iterator = std::lower_bound(indexes.begin(), indexes.end(), segment.y_coordinate);
        //What this operation does
        segment.x_coordinate = static_cast<T>(x_iterator - indexes.begin());
        segment.y_coordinate = static_cast<T>(y_iterator - indexes.begin());
    }

    std::sort(inputs.begin(), inputs.end(), [](auto &segment_a, auto &segment_b){
        return segment_a.x_coordinate < segment_b.x_coordinate;
    });

    auto fenwick_tree = cpstl::BTreeIndex<T>(indexes.size());
    for (auto &segment : inputs) {
        fenwick_tree.update(segment.y_coordinate, 1);
    }
    return fenwick_tree;
}

template <typename T, typename R>
static std::vector<R> nested_segment_fenwick_tree(std::vector<Segment<T>> &inputs)
{
    auto fenwick_tree = precompute_into_fenwick_tree(inputs);
    std::vector<R> result(inputs.size(), 0);
    for (auto &segment : inputs) {
        auto nested_segment = fenwick_tree.sum(segment.y_coordinate) - 1;
        fenwick_tree.update(segment.y_coordinate, -1);
        result[segment.index] = nested_segment;
    }
    return result;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::size_t N;
    scanf("%ld", &N);

    std::vector<Segment<long long>> inputs;
    inputs.reserve(N);
    //Read the array
    for (std::size_t index = 0; index < N; index++) {
        long long x;
        long long y;
        scanf("%lld", &x);
        scanf("%lld", &y);
        inputs.emplace_back(x, y, index);
    }

    auto result = nested_segment_fenwick_tree<long long, long long>(inputs);
    for (auto res : result)
        printf("%lld\n", res);
}

