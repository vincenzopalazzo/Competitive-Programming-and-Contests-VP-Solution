//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include <cstdlib>
#include "core/MaxSubArrayPos.h"

using namespace std;

void print_function(const int input[], const int &size_array, const vector<int> &result, const int &k){
    int index_result = 0;
    for(int i = 0; i <= size_array - k; i++){
        cout << "Array ";
        for(int j = 0; j < k; j++){
          cout << input[i + j] << "";
        }
        cout << " With max " << result.at(index_result) << endl;
        index_result++;
    }
    cout << "Size result " << result.size() << endl;
}

int main(int argc, char* argv[]){
    //int input[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    //int k = 4;
    int input[] = {958, 340, 41, 958, 694, 575, 198, 943, 23, 563, 725, 645, 787, 524, 701, 398, 599, 282, 443, 419, 282, 639,
                   918, 394, 236, 126, 218, 491, 300, 997, 409, 949, 337, 140, 906, 721, 715, 795, 353, 428, 47, 78, 72};
    int k = 27;
    const int size_array = sizeof(input) / sizeof(input[0]);
    cout << "----------- NAIVE SOLUTION -------------" << endl;
    vector<int> result = max_sub_array_naive_sol(input, size_array, k);
    print_function(input, size_array, result, k);
    cout << "----------- B BST SOLUTION -------------" << endl;
    result = max_sub_array_bbst_sol(input, size_array, k);
    print_function(input, size_array, result, k);
    cout << "----------- FIFO SOLUTION -------------" << endl;
    cout << "TODO" << endl;
    return EXIT_SUCCESS;
}
