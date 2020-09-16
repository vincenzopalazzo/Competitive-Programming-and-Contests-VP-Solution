//
// Created by vincent on 9/16/20.
// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
//

#include <iostream>
#include <vector>
#include <set>
#include <deque>


using namespace std;

template<class T>
inline void remove_minors_element(const int input[], std::deque<T> &priority_queue, const int &new_element)
{
    while (!priority_queue.empty() && input[priority_queue.back()] <= new_element) {
        //std::cout << "Remove: " << input[priority_queue.back()] << std::endl;
        priority_queue.pop_back();
    }
}

/**
 * This member is the core of the solution, because with the index we can check if the element at the top of the queue
 * is out the ranch! if I store the value inside the queue i can not make this check easy! (maybe, I can say sometings wrong)
 */
template<class T>
inline void remove_element_out_sub_array(std::deque<T> &priority_queue, const int &actual_pos, const int &size_array,
                                         const int &size_sub_array)
{

    while  (!priority_queue.empty() && actual_pos - size_sub_array >= priority_queue.front()) {
        //std::cout << "Remove auto of index: " << priority_queue.front() << std::endl;
        priority_queue.pop_front();
    }
}

//Slow
std::vector<int> max_sub_array_naive_sol(const int inputs[], const int &size_array, const int &size_sub_array)
{
    vector<int> max_values;
    max_values.reserve(size_array - size_sub_array + 1);
    for (int i = 0; i <= size_array - size_sub_array; i++) {
        int max_value = inputs[i];
        for (int j = 1; j < size_sub_array; j++) {
            if (max_value < inputs[i + j]) {
                max_value = inputs[i + j];
            }
        }
        max_values.push_back(max_value);
    }

    return max_values;
}

//Medium
const std::vector<int> max_sub_array_bbst_sol(const int input[], const int &size_array, const int &size_sub_array)
{
    std::vector<int> result;
    result.reserve(size_array - size_sub_array + 1);
    std::multiset<int> balaced_tree;
    for (int i = 0; i < size_array; i++) {
        balaced_tree.insert(input[i]);
        if (i >= size_sub_array - 1) {
            if(i - size_sub_array >= 0) {
                balaced_tree.erase(balaced_tree.find(input[i - size_sub_array]));
            }
            int max_el = *balaced_tree.rbegin();
            result.push_back(max_el);
        }
    }
    return result;
}

//Advantage
const std::vector<int> max_sub_array_deck_sol(const int input[], const int &size_array, const int &size_sub_array)
{
    std::vector<int> result;
    result.reserve(size_array - size_sub_array + 1);
    std::deque<int> priority_queue;
    for (int i = 0; i < size_array; i++) {
        //std::cout << "Insert: " << input[i] << std::endl;
        remove_minors_element(input, priority_queue, input[i]);
        priority_queue.push_back(i);
        remove_element_out_sub_array( priority_queue, i, size_array, size_sub_array);
        if (i - (size_sub_array - 1) >= 0) {
            int max = input[priority_queue.front()];
            //std::cout << "****** Max " << max << " ****** " << std::endl;
            result.push_back(max);
        }
        //std::cout << "Queue size: " << priority_queue.size() << std::endl;
    }
    return result;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        int N, K;
        cin >> N >> K;
        int A[N];
        for(int i=0;i<N;i++) cin>>A[i];
        std:vector<int> result = max_sub_array_deck_sol(A, N, K);

        for(int i=0; i < result.size(); i++)
            cout << result.at(i) << ' ';

        cout<<'\n';
    }
}}
}
