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
        cout << "\nWith max " << result.at(index_result) << endl;
        index_result++;
    }
}

int main(int argc, char* argv[]){
    int input[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 5;
    const int size_array = sizeof(input) / sizeof(input[0]);
    vector<int> result = find_max_sub_array_pos(input, size_array, k);
    print_function(input, size_array, result, k);
    return EXIT_SUCCESS;
}
