//
// Created by vincent on 9/14/20.
//
#include "MaxSum.h"
#include <iostream>
#include <climits>

using namespace std;


int max_subtree(Node *node, int &value)
{
    if (!node) return INT_MIN;
    int left_sum = max_subtree(node->left, value);
    int right_sum = max_subtree(node->right, value);

    //left node, the value is the actual date
    if (left_sum == INT_MIN && right_sum == INT_MIN) return node->data;

    int sub_tree_path = node->data;
    // calculate the sub three path, that in this case is the value of the father
    // plus the value of the bigger children
    sub_tree_path += left_sum > right_sum ? left_sum : right_sum;

    /// change value max if the node is a middle node and
    // the sum of subtree is grater that the actual max
    if (left_sum != INT_MIN && right_sum != INT_MIN) {
        int sub_tree_max = node->data + left_sum + right_sum;
        value = sub_tree_max > value ? sub_tree_max : value;
    }

    return sub_tree_path;
}

int max_path_sum(Node *node)
{
    int max = INT_MIN;
    max_subtree(node, max);
    return max;
}
