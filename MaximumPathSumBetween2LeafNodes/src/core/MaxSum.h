//
// Created by vincent on 9/14/20.
//
#include <cstdlib>
#include <string>

template<typename T>
struct Node
{
    T data;
    struct Node* left;
    struct Node* right;

    Node(T data) : data(data) {
        left = right = nullptr;
    }
};

template<typename T>
T _max_path_sum(Node<T> *node, T &max_val)
{
    if (!node) return INT32_MIN;
    int left_sum = _max_path_sum(node->left, max_val);
    int right_sum = _max_path_sum(node->right, max_val);

    //left node, the value is the actual date
    if (left_sum == INT32_MIN && right_sum == INT32_MIN) {
        return node->data;
    }

    // calculate the sub three path, that in this case is the value of the father
    // plus the value of the bigger children
    auto sub_tree_path = std::max(left_sum, right_sum) + node->data;

    /// change value max if the node is a middle node and
    // the sum of subtree is grater that the actual max
    if (left_sum != INT32_MIN && right_sum != INT32_MIN) {
        int sub_tree_max = node->data + left_sum + right_sum;
        max_val = sub_tree_max > max_val ? sub_tree_max : max_val;
    }
    return sub_tree_path;
}

template<typename T>
T max_path_sum(Node<T> *node)
{
    auto max_sum = INT32_MIN;
    _max_path_sum(node, max_sum);

    return max_sum;
}