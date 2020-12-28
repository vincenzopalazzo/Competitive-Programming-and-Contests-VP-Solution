//
// Created by vincent on 11/13/20.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

namespace cpstl
{
    template <class T>
    class LazySegmentTree
    {
    protected:
        std::vector<T> &origin;
        std::vector<T> structure;
        std::vector<T> lazy;

        /**
         * This function is used build the segment tree with a binary heap
         * implementation, and it use the origin array stored in the class.
         * @tparam T is the type of structure, usually it is a int or another numeric type
         * @param left_index the left index of the range
         * @param right_index the right index of the range
         */
        void build_structure(std::size_t left_index, std::size_t right_index)
        {
            build_structure_procedure(1, left_index, right_index - 1);
        }
        /**
         * This is the sub procedure that help the build_structure procedure to make the logic inside the segment tree
         * this version store inside the node of Segment Tree the value and not the index of the value
         * @tparam T is the type of structure, usually it is a int or another numeric type
         * @param start_index
         * @param left_index
         * @param right_index
         */
        void build_structure_procedure(std::size_t start_index, std::size_t left_index, std::size_t right_index)
        {
            if (left_index == right_index) {
                // Leaf node will have a single element
                structure[start_index] = origin[left_index];
                return;
            }
            auto middle_point = (left_index + right_index) / 2;
            auto left_child = left_child_index(start_index);
            auto right_child = right_child_index(start_index);
            build_structure_procedure(left_child, left_index, middle_point);
            build_structure_procedure(right_child, middle_point + 1, right_index);
            // Internal node will have the sum of both of its children
            auto segment_left = structure[left_child];
            auto segment_right = structure[right_child];
            structure[start_index] = (segment_left <= segment_right) ? segment_left : segment_right;
        }

        T range_query_subroutine(std::size_t start_index, std::size_t left_index, std::size_t right_index, std::size_t query_left, std::size_t query_right)
        {
            propagate(start_index, left_index, right_index);
            // outside the range
            if (query_left > right_index || query_right < left_index)  return INT64_MAX;
            // range represented by a node is completely inside the given range
            if (left_index >= query_left && right_index <= query_right)  return structure[start_index];
            // range represented by a node is partially inside and partially outside the given range
            auto middle_point = (left_index + right_index) / 2;
            auto left_child = left_child_index(start_index);
            auto right_child = right_child_index(start_index);
            auto left_segment = range_query_subroutine(left_child, left_index, middle_point,
                                                      query_left, query_right);
            auto right_segment = range_query_subroutine(right_child, middle_point + 1, right_index,
                                                       query_left, query_right);
            if (left_segment == INT64_MAX) return right_segment;
            if (right_segment == INT64_MAX) return left_segment;
            return std::min(left_segment, right_segment);
        }

        /**
         * Perform the real update of the update_range operation,
         * @param start_index: Start index, at the starting point this is 1
         * @param left_index: At the starting point it is the first position of the original array, so 0.
         * @param right_index: At the starting point it is the last position of the original array, so size - 1
         * @param from: The start index where start to update original array
         * @param to: The end index where stop to update original array
         * @param new_val: The value to sum to each position of the range in the original array.
         */
        void update_range_subroutine(std::size_t start_index, std::size_t left_index, std::size_t right_index, std::size_t from, std::size_t to, T new_val)
        {
            propagate(start_index, left_index, right_index);
            if (from > to || from > right_index || to < left_index) return;
            if((left_index >= from) && (right_index <= to)) {
                lazy[start_index] += new_val;
                propagate(start_index, left_index, right_index);
            } else {
                auto middle_point = (left_index + right_index) / 2;
                auto left_child = left_child_index(start_index);
                auto right_child = right_child_index(start_index);
                update_range_subroutine(left_child, left_index, middle_point, from, to, new_val);
                update_range_subroutine(right_child, middle_point + 1, right_index,
                                        from, to, new_val);
                auto left_subtree = structure[left_child];
                auto right_subtree = structure[right_child];
                structure[start_index] = (left_subtree <= right_subtree) ? left_subtree : right_subtree;
            }
        }

        void propagate(std::size_t start_index, std::size_t left_index, std::size_t right_index)
        {
            if (lazy[start_index] != 0) {
                // The node in position start_index was marked as lazy
                structure[start_index] += lazy[start_index];
                if (left_index != right_index) {
                    auto left_child = left_child_index(start_index);
                    auto right_child = right_child_index(start_index);
                    lazy[left_child] += lazy[start_index];
                    lazy[right_child] += lazy[start_index];
                } else {
                    // left_index = right_index is the time to update the origin array
                    origin[left_index] += lazy[start_index];
                }
                // mark as the node as not lazy
                lazy[start_index] = 0;
            }
        }

        inline std::size_t left_child_index(const int index)
        {
            return index * 2;
        }

        inline std::size_t right_child_index(const int index)
        {
            return (index * 2) + 1;
        }
    public:

        LazySegmentTree(std::vector<T> &origin): origin(origin)
        {
            std::size_t size = origin.size();
            structure = std::vector<T>(size * 4);
            lazy = std::vector<T>(size * 4);
            origin = origin;
            build_structure(0, size);
        }

        virtual ~LazySegmentTree()
        {
            structure.clear();
            lazy.clear();
        }

        T range_query(std::size_t start_index, std::size_t end_index)
        {
            return range_query_subroutine(1, 0, origin.size() - 1, start_index, end_index);
        }

        void update_range(std::size_t from, std::size_t to, T new_val)
        {
            update_range_subroutine(1, 0, origin.size() - 1, from, to, new_val);
        }

        inline std::size_t left_child(std::size_t x)
        {
            int left = left_child_index(x);
            return structure[left];
        }

        inline std::size_t right_child(std::size_t x)
        {
            int left = right_child_index(x);
            return structure[left];
        }

        inline T get_elem(std::size_t at)
        {
            return origin[at];
        }

        inline T value_at(std::size_t at)
        {
            return origin[at];
        }

        inline std::size_t get_origin_size()
        {
            return origin.size();
        }

        inline std::vector<T> get_origin()
        {
            return origin;
        }

        inline size_t size()
        {
            return structure.size();
        }
    };
};

template <typename T>
struct Query {
    size_t start;
    size_t end;
    T update_val = INT64_MAX;
    bool update = false;

    Query(size_t start, size_t anEnd) : start(start), end(anEnd) {}
    Query(size_t start, size_t anEnd, T updateVal, bool update) : start(start), end(anEnd), update_val(updateVal),
                                                                  update(update) {}
};

template <typename T>
std::vector<T> calculate_minimum_rmq_query_lazy(cpstl::LazySegmentTree<T> &segmentTree, std::vector<Query<T>> const &queries)
{
    std::vector<T> results;
    for (auto &query : queries) {
        if (query.start > query.end) {
            if (query.update) {
                segmentTree.update_range(0, query.end, query.update_val);
                segmentTree.update_range(query.start, segmentTree.size() - 1, query.update_val);
                continue;
            }
            //Is a circular RMQ query
            auto val_one = segmentTree.range_query(0, query.end);
            auto val_two = segmentTree.range_query(query.start, segmentTree.size() - 1);
            auto min = std::min(val_one, val_two);
            results.push_back(min);
            continue;
        }
        if (query.update) {
            segmentTree.update_range(query.start, query.end, query.update_val);
            continue;
        }
        // It is a normal RMQ query
        auto val = segmentTree.range_query(query.start, query.end);
        results.push_back(val);
    }
    return results;
}

template<typename T>
vector<T> read_sequence(size_t n) {
    vector<T> input(n);
    for(size_t i = 0; i < n; i++)
        cin >> input[i];
    return input;
}

int main() {
    size_t N;
    cin >> N;

    auto inputs = read_sequence<int64_t>(N);
    auto segment_tree = cpstl::LazySegmentTree<int64_t>(inputs);

    size_t K;
    cin >> K;
    std::vector<Query<int64_t>> queries;
    queries.reserve(K);
    char line[32];
    cin.getline(line, 32); // Skip newline from previous line
    for(int i = 0; i < K; i++) {
        cin.getline(line, 32);
        int64_t start = atoi(strtok(line, " "));
        int64_t end = atoi(strtok(NULL, " "));
        char* delta = strtok(NULL, " ");
        if(delta == NULL)
            queries.emplace_back(start, end);
        else
            queries.emplace_back(start, end, std::atoi(delta), true);
    }
    auto result = calculate_minimum_rmq_query_lazy(segment_tree, queries);
    for (auto elem: result) {
        cout << elem << "\n";
    }
    return EXIT_SUCCESS;
}
