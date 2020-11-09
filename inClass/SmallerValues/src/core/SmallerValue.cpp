//
// Created by vincent on 9/14/20.
//
#include "SmallerValue.h"
#include "SegmentTree.h"

using namespace std;
using namespace cpstl;

template <typename T, typename R>
vector<R> get_numbers_of_smaller_number(std::vector<T> &inputs, std::vector<Query<T>> queries)
{
    vector<R> result(queries.size());

    for (auto query : queries) {
        auto segment_tree = SegmentTree<T>(inputs, query.value);
        auto elem = segment_tree.range_query(query.start, query.end);
        result.push_back(elem);
    }
    return result;
}

template vector<int> get_numbers_of_smaller_number(std::vector<int> &inputs, std::vector<Query<int>> queries);
template class Query<int>;


