//
// Created by vincent on 9/14/20.
//
#include <cstdlib>
#include <vector>
#include "../core/MonkeyAndBamboo.h"
#include "../Utils.cpp"
#include "TestTool.cpp"

using namespace std;
using namespace cpstl;

void TEST_CASE_ONE()
{
    vector<int> inputs = {0, 1, 6, 7, 11, 13};
    auto maximum_house = estimate_dimension_k_trivial<int, int>(inputs);
    string result = "Case 1: " + to_string(maximum_house);
    assert_equal<string>("TEST_CASE_ONE", "Case 1: 5", result);
}

void TEST_CASE_ONE_DIVISION()
{
    vector<int> inputs = {0, 1, 6, 7, 11, 13};
    auto maximum_house = estimate_dimension_k_subtraction<int, int>(inputs);
    string result = "Case 1: " + to_string(maximum_house);
    assert_equal<string>("TEST_CASE_ONE_DIVISION", "Case 1: 5", result);
}

void TEST_CASE_ONE_BISECTION()
{
    vector<int> inputs = {0, 1, 6, 7, 11, 13};
    auto maximum_house = estimate_dimension_k_bisection<int, int>(inputs);
    string result = "Case 1: " + to_string(maximum_house);
    assert_equal<string>("TEST_CASE_ONE_BISECTION", "Case 1: 5", result);
}

void TEST_CASE_TWO()
{
    vector<int> inputs = {0, 3, 9, 10, 14};
    auto maximum_house = estimate_dimension_k_trivial<int, int>(inputs);
    string result = "Case 1: " + to_string(maximum_house);
    assert_equal<string>("TEST_CASE_TWO", "Case 1: 6", result);
}

void TEST_CASE_TWO_DIVISION()
{
    vector<int> inputs = {0, 3, 9, 10, 14};
    auto maximum_house = estimate_dimension_k_subtraction<int, int>(inputs);
    string result = "Case 1: " + to_string(maximum_house);
    assert_equal<string>("TEST_CASE_TWO_DIVISION", "Case 1: 6", result);
}

void TEST_CASE_TWO_BISECTION()
{
    vector<int> inputs = {0, 3, 9, 10, 14};
    auto maximum_house = estimate_dimension_k_bisection<int, int>(inputs);
    string result = "Case 1: " + to_string(maximum_house);
    assert_equal<string>("TEST_CASE_TWO_BISECTION", "Case 1: 6", result);
}

void TEST_CASE_THIRD_SUBTRACTION()
{
    string line;
    ifstream myfile ("../src/test/res/input.txt");
    std::vector<string> results;
    if (myfile.is_open())
    {
        while (getline (myfile, line) )
        {
            int tests = std::stoi(line);
            //cout << RED << "Number of tests: " << tests << RESET << "\n";
            for (int i = 1; i <= tests; i++) {
                string size_str;
                if (!getline (myfile, size_str)) {
                    break;
                }
                int size = std::stoi(size_str);
                //cout << RED << "Inputs size: " << size << RESET << "\n";
                string input_line;
                if (!getline (myfile, input_line)) {
                    break;
                }
                string delimeter = " ";
                std::vector<int> input;
                input.reserve(size + 1);
                input.push_back(0);
                for (int j = 0; j < size; j++) {
                    std::string token = input_line.substr(0, input_line.find(delimeter));
                    input_line.erase(0, input_line.find(delimeter) + delimeter.length());
                    int elem = std::stoi(token);
                    input.push_back(elem);
                }
                //print_vector(input);
                auto maximum_house = estimate_dimension_k_subtraction<int, int>(input);
                std::ostringstream stringStream;
                stringStream << "Case ";
                stringStream << i << ": " << to_string(maximum_house);
                string result = stringStream.str();
                results.push_back(result);
                //cout << RED << result << RESET << "\n";
            }
        }
        myfile.close();
        ifstream myfile ("../src/test/res/result.txt");
        string result_line;
        vector<string> aspected_result;
        if (myfile.is_open())
        {
            while ( getline (myfile,result_line) )
            {
                aspected_result.push_back(result_line);
            }
            myfile.close();
        }
        assert_equal("TEST_CASE_THIRD_SUBTRACTION", aspected_result, results);
    }
}

void TEST_CASE_THIRD_SORT()
{
    string line;
    ifstream myfile ("../src/test/res/input.txt");
    std::vector<string> results;
    if (myfile.is_open())
    {
        while (getline (myfile, line) )
        {
            int tests = std::stoi(line);
            //cout << RED << "Number of tests: " << tests << RESET << "\n";
            for (int i = 1; i <= tests; i++) {
                string size_str;
                if (!getline (myfile, size_str)) {
                    break;
                }
                int size = std::stoi(size_str);
                //cout << RED << "Inputs size: " << size << RESET << "\n";
                string input_line;
                if (!getline (myfile, input_line)) {
                    break;
                }
                string delimeter = " ";
                std::vector<int> input;
                input.reserve(size + 1);
                input.push_back(0);
                for (int j = 0; j < size; j++) {
                    std::string token = input_line.substr(0, input_line.find(delimeter));
                    input_line.erase(0, input_line.find(delimeter) + delimeter.length());
                    int elem = std::stoi(token);
                    input.push_back(elem);
                }
                //print_vector(input);
                auto maximum_house = estimate_dimension_k_trivial<int, int>(input);
                std::ostringstream stringStream;
                stringStream << "Case ";
                stringStream << i << ": " << to_string(maximum_house);
                string result = stringStream.str();
                results.push_back(result);
                //cout << RED << result << RESET << "\n";
            }
        }
        myfile.close();
        ifstream myfile ("../src/test/res/result.txt");
        string result_line;
        vector<string> aspected_result;
        if (myfile.is_open())
        {
            while ( getline (myfile,result_line) )
            {
                aspected_result.push_back(result_line);
            }
            myfile.close();
        }
        assert_equal("TEST_CASE_THIRD_SORT", aspected_result, results);
    }
}

void TEST_CASE_THIRD_BISECTION()
{
    string line;
    ifstream myfile ("../src/test/res/input.txt");
    std::vector<string> results;
    if (myfile.is_open())
    {
        while (getline (myfile, line) )
        {
            int tests = std::stoi(line);
            //cout << RED << "Number of tests: " << tests << RESET << "\n";
            for (int i = 1; i <= tests; i++) {
                string size_str;
                if (!getline (myfile, size_str)) {
                    break;
                }
                int size = std::stoi(size_str);
                //cout << RED << "Inputs size: " << size << RESET << "\n";
                string input_line;
                if (!getline (myfile, input_line)) {
                    break;
                }
                string delimeter = " ";
                std::vector<int> input;
                input.reserve(size + 1);
                input.push_back(0);
                for (int j = 0; j < size; j++) {
                    std::string token = input_line.substr(0, input_line.find(delimeter));
                    input_line.erase(0, input_line.find(delimeter) + delimeter.length());
                    int elem = std::stoi(token);
                    input.push_back(elem);
                }
                //print_vector(input);
                auto maximum_house = estimate_dimension_k_bisection<int, int>(input);
                std::ostringstream stringStream;
                stringStream << "Case ";
                stringStream << i << ": " << to_string(maximum_house);
                string result = stringStream.str();
                results.push_back(result);
                //cout << RED << result << RESET << "\n";
            }
        }
        myfile.close();
        ifstream myfile ("../src/test/res/result.txt");
        string result_line;
        vector<string> aspected_result;
        if (myfile.is_open())
        {
            while ( getline (myfile,result_line) )
            {
                aspected_result.push_back(result_line);
            }
            myfile.close();
        }
        assert_equal("TEST_CASE_THIRD_BISECTION", aspected_result, results);
    }
}

void TEST_CASE_FOUR_DIFFERENCE()
{
    string line;
    ifstream myfile ("../src/test/res/input2.txt");
    std::vector<string> results;
    if (myfile.is_open())
    {
        while (getline (myfile, line) )
        {
            int tests = std::stoi(line);
            //cout << RED << "Number of tests: " << tests << RESET << "\n";
            for (int i = 1; i <= tests; i++) {
                string size_str;
                if (!getline (myfile, size_str)) {
                    break;
                }
                int size = std::stoi(size_str);
                //cout << RED << "Inputs size: " << size << RESET << "\n";
                string input_line;
                if (!getline (myfile, input_line)) {
                    break;
                }
                string delimeter = " ";
                std::vector<int> input;
                input.reserve(size + 1);
                input.push_back(0);
                for (int j = 0; j < size; j++) {
                    std::string token = input_line.substr(0, input_line.find(delimeter));
                    input_line.erase(0, input_line.find(delimeter) + delimeter.length());
                    int elem = std::stoi(token);
                    input.push_back(elem);
                }
                //print_vector(input);
                auto maximum_house = estimate_dimension_k_subtraction<int, int>(input);
                std::ostringstream stringStream;
                stringStream << "Case ";
                stringStream << i << ": " << to_string(maximum_house);
                string result = stringStream.str();
                results.push_back(result);
                //cout << RED << result << RESET << "\n";
            }
        }
        myfile.close();
        ifstream myfile ("../src/test/res/result2.txt");
        string result_line;
        vector<string> aspected_result;
        if (myfile.is_open())
        {
            while ( getline (myfile,result_line) )
            {
                aspected_result.push_back(result_line);
            }
            myfile.close();
        }
        assert_equal("TEST_CASE_FOUR_DIFFERENCE", aspected_result, results);
    }
}

void TEST_CASE_FOUR_BISECTION()
{
    string line;
    ifstream myfile ("../src/test/res/input2.txt");
    std::vector<string> results;
    if (myfile.is_open())
    {
        while (getline (myfile, line) )
        {
            int tests = std::stoi(line);
            //cout << RED << "Number of tests: " << tests << RESET << "\n";
            for (int i = 1; i <= tests; i++) {
                string size_str;
                if (!getline (myfile, size_str)) {
                    break;
                }
                int size = std::stoi(size_str);
                //cout << RED << "Inputs size: " << size << RESET << "\n";
                string input_line;
                if (!getline (myfile, input_line)) {
                    break;
                }
                string delimeter = " ";
                std::vector<int> input;
                input.reserve(size + 1);
                input.push_back(0);
                for (int j = 0; j < size; j++) {
                    std::string token = input_line.substr(0, input_line.find(delimeter));
                    input_line.erase(0, input_line.find(delimeter) + delimeter.length());
                    int elem = std::stoi(token);
                    input.push_back(elem);
                }
                //print_vector(input);
                auto maximum_house = estimate_dimension_k_bisection<int, int>(input);
                std::ostringstream stringStream;
                stringStream << "Case ";
                stringStream << i << ": " << to_string(maximum_house);
                string result = stringStream.str();
                results.push_back(result);
                //cout << RED << result << RESET << "\n";
            }
        }
        myfile.close();
        ifstream myfile ("../src/test/res/result2.txt");
        string result_line;
        vector<string> aspected_result;
        if (myfile.is_open())
        {
            while ( getline (myfile,result_line) )
            {
                aspected_result.push_back(result_line);
            }
            myfile.close();
        }
        assert_equal("TEST_CASE_FOUR_BISECTION", aspected_result, results);
    }
}

int main()
{
    TEST_CASE_ONE();
    TEST_CASE_ONE_DIVISION();
    TEST_CASE_ONE_BISECTION();
    TEST_CASE_TWO();
    TEST_CASE_TWO_DIVISION();
    TEST_CASE_TWO_BISECTION();
    TEST_CASE_THIRD_SORT();
    TEST_CASE_THIRD_SUBTRACTION();
    TEST_CASE_THIRD_BISECTION();
    TEST_CASE_FOUR_BISECTION();
    TEST_CASE_FOUR_DIFFERENCE();

    return EXIT_SUCCESS;
}