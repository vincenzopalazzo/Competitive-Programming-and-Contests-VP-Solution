//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include <cstdlib>
#include "core/MaxSum.h"

int main(int argc, char* argv[]){
    Node *root = new Node(3);
    Node *four = new Node(4);
    root->left = four;
    Node *five = new Node(5);
    root->right = five;
    Node *double_for = new Node(4);
    four->right = double_for;
    Node *neg_ten = new Node(-10);
    four->left = neg_ten;
    int max_sum_path = max_path_sum(root);
    std::cout << "Max is: " << max_sum_path << std::endl;
    return EXIT_SUCCESS;
}