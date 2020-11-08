//
// Created by vincent on 9/14/20.
//
#include <cstdlib>
#include <vector>
#include <fstream>
#include "../core/InversionCounting.h"
#include "../Utils.cpp"
#include "TestTool.cpp"

using namespace std;
using namespace cpstl;

/**
 * This test take the input file from the test/data/input07.txt
 * parser it and return the array contained inside the substring of array.
 */
void TEST_FROM_INPUT_07()
{
    cout << BOLDWHITE << "|---------------------- TEST_FROM_INPUT_07 -----------------------|" << RESET << "\n\n";
    ifstream file_o7;
    file_o7.open("/home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/InversionCounting/src/test/data/input07.txt");
    assert(file_o7.is_open() == true);
    string line;
    file_o7 >> line;
    cout << BOLDCYAN << "Size UNIT test test: "  << line << "\n";
    int test = stoi(line);
    for (int i = 0; i < test; i++) {
        file_o7 >> line;
        //cout << BOLDCYAN << "Size array: " << line << "\n";
        int size = stoi(line);
        getline(file_o7, line);
        while (line.empty()) {
            getline(file_o7, line);
        }
        std::vector<string> inputs_token = load_input_from_string<string>(line);
        assert(inputs_token.size() == size);
        std::vector<int> inputs(size);
        long result[] = {
            0, 0, 0, 4999950000, 4999950000
        };
        for (int j = 0; j < inputs_token.size(); j++) {
            inputs[j] = stoi(inputs_token[j]);
        }
        long inversions_merge = count_inversion_merge_sort<int, long>(inputs);
        assert_equal(("input_05_" + to_string(i)), result[i], inversions_merge);
    }
}

int main()
{
    vector<int> inputs = {2, 3, 8, 6, 1};
    print_vector(inputs);
    long inversions_merge = count_inversion_merge_sort<int, long>(inputs);
    assert_equal("One", (long)5, inversions_merge);

    inputs = {3, 1, 2};
    print_vector(inputs);
    inversions_merge = count_inversion_merge_sort<int, long>(inputs);
    assert_equal("Two", (long)2, inversions_merge);

    //Example from https://www.youtube.com/watch?v=owZhw-A0yWE&t=111s
    inputs = {1, 20, 6, 7, 5, 8, 11, 3};
    print_vector(inputs);
    inversions_merge = count_inversion_merge_sort<int, long>(inputs);
    assert_equal("Tree", (long)13, inversions_merge);

    //FROM example https://www.geeksforgeeks.org/counting-inversions/#:~:text=Inversion%20Count%20for%20an%20array,inversion%20count%20is%20the%20maximum.
    //{8, 4, 2, 1}
    inputs = {8, 4, 2, 1};
    print_vector(inputs);
    inversions_merge = count_inversion_merge_sort<int, long>(inputs);
    assert_equal("Four", (long)6, inversions_merge);

    //FROM example https://www.cp.eng.chula.ac.th/~prabhas//teaching/algo/algo2008/count-inv.htm
    //{2, 4, 1, 3, 5}
    inputs = {2, 4, 1, 3, 5};
    print_vector(inputs);
    inversions_merge = count_inversion_merge_sort<int, long>(inputs);
    assert_equal("Five", (long)3, inversions_merge);

    TEST_FROM_INPUT_07();

    return EXIT_SUCCESS;
}