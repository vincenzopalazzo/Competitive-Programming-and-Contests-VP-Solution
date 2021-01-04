//
// Created by vincent on 10/4/20.
//

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct Node
{
    T data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int max_subtree(Node *node, int &value)
{
    if (!node) return INT32_MIN;
    int left_sum = max_subtree(node->left, value);
    int right_sum = max_subtree(node->right, value);

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
        value = sub_tree_max > value ? sub_tree_max : value;
    }
    return sub_tree_path;
}

int maxPathSum(Node *node)
{
    int max_sum = INT_MIN;
    max_subtree(node, max_sum);
    if (max_sum == INT32_MIN) // If the btree has only the root
        max_sum = node->data;
    return max;
}