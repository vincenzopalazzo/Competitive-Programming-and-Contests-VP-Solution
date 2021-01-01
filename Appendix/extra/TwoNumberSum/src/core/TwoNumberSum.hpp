//
// Created by vincent on 9/14/20.
//
#include <vector>
#include <algorithm>
#include <unordered_set>
/*
 * This solution is the naive solution that i wrote for algoexpert.io.
 * The time complexity is O(n^2) in the worst case and the space complexity is O(1)
 * because I don't use any additional space
 */
template <typename T>
std::vector<T> get_element_to_get_sum(std::vector<T> &inputs, T required_sum)
{
  std::vector<T> result(2, 0);

  for (std::size_t i = 0; i < inputs.size(); i++) {
    for (std::size_t j = i + 1; j < inputs.size(); j++) {
      if (inputs[i] + inputs[j] == required_sum) {
        result[0] = inputs[i];
        result[1] = inputs[j];
        return result;
      }
    }
  }
  return {};
}


/*
 * We can store the value in a hash table to keep track of the number X and
 * during the scanning we keep track the solution to get the X from the hashtb end
 * apply the formula y = TARGET_NUM - x, if there is y in the hash table we are done.
 * Time complexity is linear O(n) and space complexity is linear O(n)
 */
template<typename T>
std::vector<T> get_element_to_get_sum_hasttb(std::vector<T> const &inputs, T target_num)
{
  std::unordered_set<T> tracking;

  for (auto elem : inputs) {
    auto wanted_elem = target_num - elem;
    if (tracking.find(wanted_elem) != tracking.end()) {
      return {elem, wanted_elem};
    }
    tracking.insert(elem);
  }
  return {};
}

/*
 * Better solution to solve the problem in O(N log N) that use the sort and the two
 * pointer tecnique.
 */
template<typename T>
std::vector<T> get_element_to_get_sum_two_pointer(std::vector<T> &inputs, T target_num)
{
  std::sort(inputs.begin(), inputs.end());

  int x = 0;
  int y = inputs.size() - 1;
  while (x < y) {
    auto sum = inputs[x] + inputs[y];
    if (sum == target_num) {
      return {inputs[x], inputs[y]};
    }

    if (sum < target_num)
      x++;
    else
      y--;
  }
  return {};
}
