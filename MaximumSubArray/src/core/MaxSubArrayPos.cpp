//
// Created by vincent on 9/14/20.
//
#include "MaxSubArrayPos.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int>& find_max_sub_array_pos(const int* input, const int size)
{
    vector<int> max_sub_arr = vector<int>();
    int sub_array_sum = 0;
    int sum = 0; //tmp sum;
    for(int i = 0; i < size; i++){
        if(input[i] < 0){
            sum = 0;
            max_sub_arr.erase(max_sub_arr.end());
        }
    }

    return max_sub_arr;
}

int sizeArray(const int* array){
    return sizeof(array) / sizeof(*array);
}