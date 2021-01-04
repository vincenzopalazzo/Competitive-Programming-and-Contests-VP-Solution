//
// Created by vincent on 9/14/20.
//

template<typename T>
struct Node {
  T value;
  Node *left, *right;
};

template<class T>
class Utils {
private:
  inline static T get_clotest_value_recursive_help(Node<T> *node, T target, T clotest)
  {
    return -1;
  }

public:
  inline static T get_clotest_value_recursive(Node<T> *root, T target)
  {
    return get_clotest_value_recursive_help(root, target, root->value);
  }

  inline static T get_clotest_value_iterative(Node<T> *root, int target)
  {
    auto current_node = root;
    auto clotest = root->value;
    while (current_node) {
      auto current_delta = std::abs(target - clotest);
      auto new_delta = std::abs(target - current_node->value);
      if (current_delta > new_delta)
        clotest = current_node->value;
      if(current_node->value < target)
        current_node = current_node->right;
      else
        current_node = current_node->left;
    }
    return clotest;
  }
};
