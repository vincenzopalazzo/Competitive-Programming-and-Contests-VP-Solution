//
// Created by vincent on 9/14/20.
//
//Submission: https://practice.geeksforgeeks.org/viewSol.php?subId=d222beb3ec864172e96d4bfa5b7a5969&pid=451&user=vpalazzo1
//
#include <iostream>
#include <cstdlib>
#include "core/MaxSubArrayPos.h"

using namespace std;

void print_function(const std::vector<int> input, int size_array, vector<int> &result, int k){
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
    std::vector<int> input = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int k = 3;
    /*int input[] = {958, 340, 41, 958, 694, 575, 198, 943, 23, 563, 725, 645, 787, 524, 701, 398, 599, 282, 443, 419, 282, 639,
                   918, 394, 236, 126, 218, 491, 300, 997, 409, 949, 337, 140, 906, 721, 715, 795, 353, 428, 47, 78, 72};
    int k = 27;

    std::vector<int> input = {765, 992, 1, 521, 220, 380, 729, 969, 184, 887, 104, 641, 909, 378, 724, 582, 387, 583, 241, 294, 159, 198, 653, 369, 418, 692, 36, 901, 516, 623, 703, 971, 304, 394, 491, 525, 464, 219, 183, 648,
                   796, 287, 979, 395, 356, 702, 667, 743, 976, 908, 728, 134, 106, 380, 193, 214, 71, 920, 114, 587, 543, 817, 248, 537, 901, 739, 752, 364, 649, 626, 702, 444, 913, 681, 529, 959, 72, 196, 392, 738, 103, 119, 872, 900};
    int k = 47;*/
    const int size_array = input.size();

    cout << "----------- NAIVE SOLUTION -------------" << endl;
    vector<int> result = max_sub_array_naive_sol(input, size_array, k);
    print_function(input, size_array, result, k);
    cout << "----------- B BST SOLUTION -------------" << endl;
    result = max_sub_array_bbst_sol(input, size_array, k);
    print_function(input, size_array, result, k);
    cout << "----------- FIFO SOLUTION -------------" << endl;
    result = max_sub_array_deck_sol(input, size_array, k);
    print_function(input, size_array, result, k);
    return EXIT_SUCCESS;
}
