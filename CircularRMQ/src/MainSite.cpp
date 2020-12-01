//
// Created by vincent on 11/13/20.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

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
        void build_structure(int left_index, int right_index) {
            build_structure_procedure(1, left_index, right_index - 1);
        }

        /**
         * This is the sub procedure that help the build_structure procedure to make the logic inside the segment tree
         * @tparam T is the type of structure, usually it is a int or another numeric type
         * @param start_index
         * @param left_index
         * @param right_index
         */
        void build_structure_procedure(int start_index, int left_index, int right_index) {
            if (left_index == right_index) {
                // Leaf node will have a single element
                structure[start_index] = left_index;
                return;
            }
            int middle_point = (left_index + right_index) / 2;
            int left_child = left_child_index(start_index);
            int right_child = right_child_index(start_index);
            build_structure_procedure(left_child, left_index, middle_point);
            build_structure_procedure(right_child, middle_point + 1, right_index);
            // Internal node will have the sum of both of its children
            int segment_left = structure[left_child];
            int segment_right = structure[right_child];
            structure[start_index] = (origin[segment_left] <= origin[segment_right]) ? segment_left : segment_right;
        }

        int range_query_subroutine(int start_index, int left_index_now, int right_index_now, int query_left,
                                   int query_right) {
            if (query_left > right_index_now || query_right < left_index_now) return -1; // outside the range
            if (left_index_now >= query_left && right_index_now <= query_right)
                return structure[start_index]; // range represented by a node is completely inside the given range
            // range represented by a node is partially inside and partially outside the given range
            int middle_point = (left_index_now + right_index_now) / 2;
            int left_child = left_child_index(start_index);
            int right_child = right_child_index(start_index);
            int left_segment = range_query_subroutine(left_child, left_index_now, middle_point,
                                                      query_left, query_right);
            int right_segment = range_query_subroutine(right_child, middle_point + 1, right_index_now,
                                                       query_left, query_right);
            if (left_segment == -1) return right_segment;
            if (right_segment == -1) return left_segment;
            return (origin[left_segment] <= origin[right_segment]) ? left_segment : right_segment;
        }

        void update_subroutine(int start_index, int left_index, int right_index, int pos, T new_value) {
            if (left_index == right_index) {
                origin[pos] += new_value;
                structure[start_index] = pos;
            } else {
                int middle_point = (left_index + right_index) / 2;
                int left_child = left_child_index(start_index);
                int right_child = right_child_index(start_index);
                if (pos <= middle_point) {
                    update_subroutine(left_child, left_index, middle_point, pos, new_value);
                } else {
                    update_subroutine(right_child, middle_point + 1, right_index, pos, new_value);
                }
                int segment_left = structure[left_child];
                int segment_right = structure[right_child];
                structure[start_index] = (origin[segment_left] <= origin[segment_right]) ? segment_left : segment_right;
            }
        }

        inline int left_child_index(const int index) {
            //return index << 1;
            return index * 2;
        }

        inline int right_child_index(const int index) {
            //return (index << 1) + 1;
            return (index * 2) + 1;
        }

    public:

        SegmentTree(std::vector<T> &origin) : origin(origin) {
            int size = origin.size();
            structure = std::vector<T>(size * 4);
            origin = origin;
            build_structure(0, size);
        }

        virtual ~SegmentTree() {
            structure.clear();
        }

        int range_query(int start_index, int end_index) {
            return range_query_subroutine(1, 0, origin.size() - 1, start_index, end_index);
        }

        /**
         * This is the sub procedure that help the build_structure procedure to make the logic inside the segment tree
         * @param at: it is the position in the original array, the function change the value also in the original array
         * @param new_value the value that we want override in position at.
         */
        void update(int at, T value) {
            update_subroutine(1, 0, origin.size() - 1, at, value);
        }

        inline int left_child(int x) {
            int left = left_child_index(x);
            return structure[left];
        }

        inline int right_child(int x) {
            int left = right_child_index(x);
            return structure[left];
        }

        inline T get_elem(int at) {
            return origin[at];
        }

        inline size_t get_origin_size() {
            return origin.size();
        }

        inline std::vector<T> get_orgin() {
            return origin;
        }

    };
};

template<typename T>
struct Query {
    size_t start;
    size_t end;
    T update_val = INT64_MAX;

    Query(size_t start, size_t anEnd) : start(start), end(anEnd) {}
};


template<typename T>
std::vector<T> calculate_minimum_rmq_query(cpstl::SegmentTree<T> &segmentTree, std::vector<Query<T>> const &queries) {
    std::vector<T> results;
    results.reserve(queries.size());
    for (auto query : queries) {
        if (query.start > query.end) {
            if (query.update_val != INT32_MIN) {
                for (int i = 0; i <= query.start; i++)
                    segmentTree.update(i, query.update_val);
                for (int i = query.start; i <= segmentTree.get_origin_size() - 1; i++)
                    segmentTree.update(i, query.update_val);
                continue;
            }
            //Is a circular RMQ query
            auto first_query = Query<T>(0, query.start);
            auto second_query = Query<T>(query.end, segmentTree.get_origin_size() - 1);

            auto index_val = segmentTree.range_query(first_query.start, first_query.end);
            auto val_one = segmentTree.get_elem(index_val);
            index_val = segmentTree.range_query(second_query.start, second_query.end);
            auto val_two = segmentTree.get_elem(index_val);
            auto min = std::min(val_one, val_two);
            results.push_back(min);
            continue;
        }
        if (query.update_val != INT32_MIN) {
            for (int i = query.start; i <= query.end; i++)
                segmentTree.update(i, query.update_val);
            continue;
        }
        // It is a normal RMQ query
        auto index_val = segmentTree.range_query(query.start, query.end);
        auto val = segmentTree.get_elem(index_val);
        cout << "----\n";
        results.push_back(val);
    }
    return results;
}


int main() {
    int N;
    cin >> N;
    std::vector<int> inputs;
    inputs.reserve(N);
    for (std::size_t i = 0; i < N; i++) {
        long long val;
        cin >> val;
        cout << val << " ";
        inputs.push_back(val);
    }
    int m;
    cin >> m;
    std::vector<Query<int>> queries;
    queries.reserve(m);
    for(std::size_t i = 1; i <= m; i++) {
        long long x, y;
        cin >> x >> y;
        char c = getchar();
        if (c == '\n') {
            cout << "\n" << x << " " << y << " ";
            queries.emplace_back(x, y);
        } else {
            queries.emplace_back(x, y);
            long long q;
            auto query = queries.back();
            cin >> q;
            query.update_val = q;
            cout << "\n" << x << " " << y << " " << q;
        }
    }
    cout << "\nQ: " << queries.size();

    auto segment_tree = cpstl::SegmentTree<int>(inputs);
    auto result = calculate_minimum_rmq_query(segment_tree, queries);
    cout << "\nR: " << result.size();
    for (auto res : result)
        printf("%lld\n", res);
}
