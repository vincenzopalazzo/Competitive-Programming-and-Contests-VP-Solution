//
// Created by vincent on 9/14/20.
//
#ifndef SPYCBLOCK_SOLTEST_H
#define SPYCBLOCK_SOLTEST_H
#include <cstdlib>
#include <string>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int max_path_sum(Node *node);

#endif //SPYCBLOCK_SOLTEST_H
