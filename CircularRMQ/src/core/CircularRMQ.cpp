//
// Created by vincent on 9/14/20.
//
#include "CircularRMQ.h"
#include <iostream>

using namespace std;

/**
 * Some idea about the Circular problem.
 * We can brake tha query in two part and make two query to compute the result.
 *
 * E.S: Query (3, 0):
 * - If the query have start > end, this mean that we need to break the query in two part.
 * - otherwise we java a normal query
 */
template <typename T>
std::vector<T> calculate_minimum_rmq_query(cpstl::SegmentTree<T> &segmentTree, std::vector<Query<T>> const &queries)
{
    std::vector<T> results;
    results.reserve(queries.size());
    for (auto query : queries) {
        cpstl::cp_log(LOG, segmentTree.get_orgin());
        cpstl::cp_log(LOG, "Query (" + to_string(query.start) + ", " + to_string(query.end) + ")");

        if (query.start > query.end) {
            cpstl::cp_log(LOG, "Is circular");
            if (query.update_val != INT32_MIN) {
                cpstl::cp_log(LOG, "Update query with value: " + to_string(query.update_val));
                for (int i = 0; i <= query.start; i++)
                    segmentTree.update(i, query.update_val);
                for (int i = query.start; i <= segmentTree.get_origin_size(); i++)
                    segmentTree.update(i, query.update_val);
                continue;
            }
            //Is a circular RMQ query
            auto first_query = Query<T>(0, query.start);
            auto second_query = Query<T>(query.end, segmentTree.get_origin_size() - 1);

            auto index_val = segmentTree.range_query(first_query.start, first_query.end);
            auto val_one = segmentTree.get_elem(index_val);
            cpstl::cp_log(LOG, "Minimum in the first query is: " + to_string(val_one));
            index_val = segmentTree.range_query(second_query.start, second_query.end);
            auto val_two = segmentTree.get_elem(index_val);
            cpstl::cp_log(LOG, "Minimum in the second query is: " + to_string(val_two));
            auto min = std::min(val_one, val_two);
            cpstl::cp_log(LOG, "Minimum in the query is: " + to_string(min));
            results.push_back(min);
            continue;
        }
        if (query.update_val != INT32_MIN) {
            cpstl::cp_log(LOG, "Update query with value: " + to_string(query.update_val));
            for (int i = query.start; i <= query.end; i++)
                segmentTree.update(i, query.update_val);
            continue;
        }
        // It is a normal RMQ query
        auto index_val = segmentTree.range_query(query.start, query.end);
        auto val = segmentTree.get_elem(index_val);
        cpstl::cp_log(LOG, "Minimum in the query is: " + to_string(val));
        results.push_back(val);
    }
    return results;
}

template std::vector<int> calculate_minimum_rmq_query(cpstl::SegmentTree<int> &segmentTree, std::vector<Query<int>> const &queries);
