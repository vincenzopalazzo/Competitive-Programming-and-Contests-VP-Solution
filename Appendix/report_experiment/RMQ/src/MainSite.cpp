//
// Created by vincent on 11/13/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <vector>

namespace cpstl {
    template<class T>
    class SegmentTree {
    private:
        std::vector<T> &origin;
        std::vector<T> structure;

        /**
         * This function is used build the segment tree with a binary heap
         * implementation, and it use the origin array stored in the class.
         * @tparam T is the type of structure, usually it is a int or another numeric type
         * @param left_index the left index of the range
         * @param right_index the right index of the range
         */
        void build_structure(std::size_t left_index, std::size_t right_index) {
            build_structure_procedure(1, left_index, right_index - 1);
        }

        /**
         * This is the sub procedure that help the build_structure procedure to make the logic inside the segment tree
         * @tparam T is the type of structure, usually it is a int or another numeric type
         * @param start_index
         * @param left_index
         * @param right_index
         */
        void build_structure_procedure(std::size_t start_index, std::size_t left_index, std::size_t right_index) {
            if (left_index == right_index) {
                // Leaf node will have a single element
                structure[start_index] = left_index;
                return;
            }
            std::size_t middle_point = (left_index + right_index) / 2;
            std::size_t left_child = left_child_index(start_index);
            std::size_t right_child = right_child_index(start_index);
            build_structure_procedure(left_child, left_index, middle_point);
            build_structure_procedure(right_child, middle_point + 1, right_index);
            // Internal node will have the sum of both of its children
            std::size_t segment_left = structure[left_child];
            std::size_t segment_right = structure[right_child];
            structure[start_index] = (origin[segment_left] <= origin[segment_right]) ? segment_left : segment_right;
        }

        int range_query_subroutine(std::size_t start_index, std::size_t left_index_now, std::size_t right_index_now,
                                   std::size_t query_left, std::size_t query_right) {
            if (query_left > right_index_now || query_right < left_index_now) return -1; // outside the range
            if (left_index_now >= query_left && right_index_now <= query_right)
                return structure[start_index]; // range represented by a node is completely inside the given range
            // range represented by a node is partially inside and partially outside the given range
            std::size_t middle_point = (left_index_now + right_index_now) / 2;
            std::size_t left_child = left_child_index(start_index);
            std::size_t right_child = right_child_index(start_index);
            std::size_t left_segment = range_query_subroutine(left_child, left_index_now, middle_point,
                                                              query_left, query_right);
            std::size_t right_segment = range_query_subroutine(right_child, middle_point + 1, right_index_now,
                                                               query_left, query_right);
            if (left_segment == -1) return right_segment;
            if (right_segment == -1) return left_segment;
            return (origin[left_segment] <= origin[right_segment]) ? left_segment : right_segment;
        }

        void update_subroutine(std::size_t start_index, std::size_t left_index, std::size_t right_index, std::size_t pos,
                          T new_value) {
            if (left_index == right_index) {
                origin[pos] = new_value;
                structure[start_index] = pos;
                return;
            }
            size_t middle_point = (left_index + right_index) / 2;
            size_t left_child = left_child_index(start_index);
            size_t right_child = right_child_index(start_index);
            if (pos <= middle_point) {
                update_subroutine(left_child, left_index, middle_point, pos, new_value);
            } else {
                update_subroutine(right_child, middle_point + 1, right_index, pos, new_value);
            }
            size_t segment_left = structure[left_child];
            size_t segment_right = structure[right_child];
            structure[start_index] = (origin[segment_left] <= origin[segment_right]) ? segment_left : segment_right;
        }

        inline int left_child_index(const std::size_t index) {
            //return index << 1;
            return index * 2;
        }

        inline int right_child_index(const std::size_t index) {
            //return (index << 1) + 1;
            return (index * 2) + 1;
        }

    public:

        SegmentTree(std::vector<T> &origin) : origin(origin) {
            std::size_t size = origin.size();
            structure = std::vector<T>(size * 4);
            origin = origin;
            build_structure(0, size);
        }

        virtual ~SegmentTree() {
            structure.clear();
        }

        int range_query(std::size_t start_index, std::size_t end_index) {
            return range_query_subroutine(1, 0, origin.size() - 1, start_index, end_index);
        }

        /**
         * This is the sub procedure that help the build_structure procedure to make the logic inside the segment tree
         * @param at: it is the position in the original array, the function change the value also in the original array
         * @param new_value the value that we want override in position at.
         */
        void update(std::size_t at, T value) {
            update_subroutine(1, 0, origin.size() - 1, at, value);
        }

        inline int left_child(std::size_t x) {
            int left = left_child_index(x);
            return structure[left];
        }

        inline int right_child(std::size_t x) {
            int left = right_child_index(x);
            return structure[left];
        }

        inline T value_at(std::size_t at) {
            return origin[at];
        }

    };
};

template<typename T>
struct Query {
    bool update;
    T start;
    T end;

    Query(bool type, T start, T anEnd) : update(type), start(start), end(anEnd) {}
};

template <typename T>
std::vector<T> range_minimum_query_segment_tree(cpstl::SegmentTree<T> &segmentTree, std::vector<Query<T>> &queries)
{
    std::vector<T> results;
    results.reserve(queries.size());
    for (auto &query : queries) {
        if (query.update) {
            segmentTree.update(query.start - 1, query.end);
            continue;
        }
        auto res = segmentTree.range_query(query.start - 1, query.end - 1);
        results.push_back(segmentTree.value_at(res));
    }
    return results;
}

int main() {
    int N, Q;
    scanf("%d", &N);
    scanf("%d", &Q);

    std::vector<int> inputs;
    inputs.reserve(N);
    //Read the array
    for (std::size_t t = 0; t < N; t++) {
        int value;
        scanf("%d", &value);
        inputs.push_back(value);
    }

    std::vector<Query<int>> queries;
    queries.reserve(Q);
    //read query
    for (int i = 0; i < Q; i++) {
        char type;
        int start, end;
        cin >> type;
        scanf("%d", &start);
        scanf("%d", &end);
        if (type == 'u') {
            queries.emplace_back(true, start, end);
            continue;
        }
        queries.emplace_back(false, start, end);
    }

    auto segment_tree = cpstl::SegmentTree<int>(inputs);
    auto result = range_minimum_query_segment_tree(segment_tree, queries);
    for (auto res : result) {
        printf("%d\n", res);
    }
}
