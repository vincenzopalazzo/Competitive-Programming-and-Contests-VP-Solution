//
// Created by vincent on 10/17/20.
//
#include <cassert>
#include "FenwickTree.h"

template<class T>
void cpstl::BTreeIndex<T>::update(const T &value, int at)
{
    for (++at; at < structure.size(); at += at&-at) {
        structure[at] += value;
    }
}

template<class T>
T cpstl::BTreeIndex<T>::sum(int begin, int end)
{
    T sum = 0;
    for (++end; end > begin; end &= end - 1) {
        sum += structure[end];
    }
    return sum;
}

template<class T>
T cpstl::BTreeIndex<T>::sum(int end)
{
    T sum = 0;
    for (++end; end > 0; end &= end - 1) {
        sum += structure[end];
    }
    return sum;
}

template<class T>
int cpstl::BTreeIndex<T>::min(T const value) {
    assert(false && "Not implemented yet");
    return -1;
}

template<class T>
int cpstl::BTreeIndex<T>::max(T const value) {
    assert(false && "Not implemented yet");
    return -1;
}

template<class T>
cpstl::BTreeIndex<T>::BTreeIndex(int size)
{
    structure = std::vector<T>(size + 1);
}

template<class T>
cpstl::BTreeIndex<T>::BTreeIndex(const std::vector<T> &structure)
{
    this->structure.reserve(structure.size() + 1);
    this->structure[0] = 0;
    for (int i = 0; i < structure.size(); i++) {
        this->structure[i + 1] = structure[i];
    }

    int at = 1;
    while (at < this->structure.size()) {
        int at_tree = at&-at;
        this->structure[at_tree] += this->structure[at];
        at += at&-at;
    }
}

template class cpstl::BTreeIndex<int>;