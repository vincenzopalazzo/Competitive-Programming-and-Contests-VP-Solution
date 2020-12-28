//
// Created by vincent on 9/14/20.
//
#ifndef SPYCBLOCK_SOLTEST_H
#define SPYCBLOCK_SOLTEST_H

#include <cstring>
#include "../test/Utils.hpp"
#include "SegmentTree.h"
#include "LazySegmentTree.h"

const cpstl::Log LOG(false);

template <typename T>
struct Query {
    size_t start;
    size_t end;
    T update_val = INT32_MIN;
    bool update = false;

    Query(size_t start, size_t anEnd) : start(start), end(anEnd) {}
    Query(size_t start, size_t anEnd, T updateVal, bool update) : start(start), end(anEnd), update_val(updateVal),
                                                                  update(update) {}
};

template <typename T>
std::vector<T> calculate_minimum_rmq_query(cpstl::SegmentTree<T> &segmentTree, std::vector<Query<T>> const &queries)
{
    std::vector<T> results;
    results.reserve(queries.size());
    for (auto &query : queries) {
        cpstl::cp_log(LOG, "Query (" + std::to_string(query.start) + ", " + std::to_string(query.end) + ")");
        if (query.start > query.end) {
            cpstl::cp_log(LOG, "Is circular");
            if (query.update) {
                cpstl::cp_log(LOG, "Update query with value: " + std::to_string(query.update_val));
                for (int i = 0; i <= query.end; i++)
                    segmentTree.update(i, query.update_val);
                for (int i = query.start; i <= segmentTree.get_origin_size() - 1; i++)
                    segmentTree.update(i, query.update_val);
                cpstl::cp_log(LOG, "Result update");
                cpstl::cp_log(LOG, segmentTree.get_orgin());
                continue;
            }
            //Is a circular RMQ query
            auto index_val = segmentTree.range_query(0, query.end);
            auto val_one = segmentTree.get_elem(index_val);
            index_val = segmentTree.range_query(query.start, segmentTree.get_origin_size() - 1);
            auto val_two = segmentTree.get_elem(index_val);
            auto min = std::min(val_one, val_two);
            results.push_back(min);
            continue;
        }
        if (query.update) {
            cpstl::cp_log(LOG, "Update query with value: " + std::to_string(query.update_val));
            for (int i = query.start; i <= query.end; i++)
                segmentTree.update(i, query.update_val);
            cpstl::cp_log(LOG, "Result update");
            cpstl::cp_log(LOG, segmentTree.get_orgin());
            continue;
        }
        // It is a normal RMQ query
        auto index_val = segmentTree.range_query(query.start, query.end);
        auto val = segmentTree.get_elem(index_val);
        cpstl::cp_log(LOG, "Minimum in the query is: " + std::to_string(val));
        results.push_back(val);
    }
    cpstl::cp_log(LOG, "Final Result");
    cpstl::cp_log(LOG, segmentTree.get_orgin());
    return results;
}

template <typename T>
std::vector<T> calculate_minimum_rmq_query_lazy(cpstl::LazySegmentTree<T> &segmentTree, std::vector<Query<T>> const &queries)
{
    std::vector<T> results;
    results.reserve(queries.size());
    for (auto &query : queries) {
        if (query.start > query.end) {
            cpstl::cp_log(LOG, "Is circular");
            if (query.update) {
                cpstl::cp_log(LOG, true, "Query (" + std::to_string(query.start) + ", " + std::to_string(query.end) +
                        ") *Update query with value: " + std::to_string(query.update_val));
                segmentTree.update_range(0, query.end, query.update_val);
                segmentTree.update_range(query.start, segmentTree.size() - 1, query.update_val);
                cpstl::cp_log(LOG, "Result update");
                cpstl::cp_log(LOG, segmentTree.get_origin());
                continue;
            }
            //Is a circular RMQ query
            auto val_one = segmentTree.range_query(0, query.end);
            auto val_two = segmentTree.range_query(query.start, segmentTree.size() - 1);
            cpstl::cp_log(LOG, "Query (0, " + std::to_string(query.end) + ") -> " + std::to_string(val_one));
            cpstl::cp_log(LOG, "Query (" + std::to_string(query.start) + ", " + std::to_string(segmentTree.get_origin_size() - 1) +
                                    ") -> " + std::to_string(val_two));
            auto min = std::min(val_one, val_two);
            cpstl::cp_log(LOG, true, "Size result: " + std::to_string(results.size()) + " " + std::to_string(min));
            results.push_back(min);
            continue;
        }
        if (query.update) {
            cpstl::cp_log(LOG, true, "Query (" + std::to_string(query.start) + ", " + std::to_string(query.end) +
                            ") *Update query with value: " + std::to_string(query.update_val));
            segmentTree.update_range(query.start, query.end, query.update_val);
            cpstl::cp_log(LOG, "Result update");
            cpstl::cp_log(LOG, segmentTree.get_origin());
            continue;
        }
        // It is a normal RMQ query
        auto val = segmentTree.range_query(query.start, query.end);
        cpstl::cp_log(LOG, "Minimum in the query is: " + std::to_string(val));
        cpstl::cp_log(LOG, true, "Size result: " + std::to_string(results.size()) + " " + std::to_string(val));
        results.push_back(val);
    }
    cpstl::cp_log(LOG, "Final Result");
    cpstl::cp_log(LOG, segmentTree.get_origin());
    return results;
}

#endif //SPYCBLOCK_SOLTEST_H
