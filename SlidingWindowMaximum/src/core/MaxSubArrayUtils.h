//
// Created by vincent on 9/16/20.
//

#ifndef MAXIMUMINSUMARRAYS_MAXSUBARRAYUTILS_H
#define MAXIMUMINSUMARRAYS_MAXSUBARRAYUTILS_H

#include <deque>
#include <ctime>

inline int tic(){
    return clock();
}

inline float toc(int startTime){
    return (double)(clock() - (float)startTime) / CLOCKS_PER_SEC;
}

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

#endif //MAXIMUMINSUMARRAYS_MAXSUBARRAYUTILS_H
