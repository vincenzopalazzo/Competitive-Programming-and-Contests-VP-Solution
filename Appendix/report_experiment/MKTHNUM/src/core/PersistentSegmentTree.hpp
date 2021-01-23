/**
 * Segment tree data structure implementation
 * Copyright (C) 2020  Vincenzo Palazzo vincenzopalazzodev@gmail.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */
#include <iostream>
#include <memory>
#include <vector>

namespace cpstl {
template <typename T>
struct Node {
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;
  T value;

  Node(std::shared_ptr<Node> left, std::shared_ptr<Node> right)
      : left(left), right(right), value(0) {
    T left_val, right_val = 0;
    if (left) left_val = left->value;
    if (right) right_val = right->value;
    value += (right->value + left->value);
  }
  Node(T value) : left(nullptr), right(nullptr), value(value) {}
};

template <class T>
class PersistentSegmentTree {
 protected:
  std::shared_ptr<Node<T>> root;
  std::vector<std::shared_ptr<Node<T>>> history;

  std::shared_ptr<Node<T>> build_structure(int left_index, int right_index) {
    return build_structure_procedure(left_index, right_index);
  }

  std::shared_ptr<Node<T>> build_structure_procedure(int left_index,
                                                     int right_index) {
    if (left_index == right_index) {
      // Leaf node will have a single element
      return std::make_shared<Node<T>>(0);
    }
    int middle_point = (left_index + right_index) / 2;
    auto node_left = build_structure_procedure(left_index, middle_point);
    auto node_right = build_structure_procedure(middle_point + 1, right_index);
    return std::make_shared<Node<T>>(node_left, node_right);
  }

  int range_query_subroutine(std::shared_ptr<Node<T>> &first_node,
                             std::shared_ptr<Node<T>> &second_node,
                             int left_index, int right_index, int  target) {
    if (left_index == right_index)
      return left_index;

    auto middle_point = (left_index + right_index) / 2;
    auto left_count = first_node->target + second_node->target;
    if (left_count >= target)
      return range_query_subroutine(first_node->left_node, second_node->left_node, left_index, middle_point, target);
    return range_query_subroutine(first_node->right_node, second_node->right_node, middle_point + 1, right_index, target);
  }

  std::shared_ptr<Node<T>> update_range_subroutine(
      std::shared_ptr<Node<T>> &node, int left_index, int right_index, int pos) {
    if (left_index == right_index || !node) {
      return std::make_shared<Node<T>>(node->target + 1);
    }

    int middle_point = (left_index + right_index) / 2;

    if (pos <= middle_point) {
      auto left_node = update_range_subroutine(node->left, left_index,
                                               middle_point, pos, new_val);
      return std::make_shared<Node<T>>(left_node, node->right);
    }

    auto right_node = update_range_subroutine(node->right, middle_point + 1,
                                              right_index, pos, new_val);
    return std::make_shared<Node<T>>(node->left, right_node);
  }

 public:
  PersistentSegmentTree() {}

  virtual ~PersistentSegmentTree() {
    root.reset();
    history.clear();
  }

  int range_query(int start_index, int end_index) {
    return range_query_subroutine(root, 0, origin.size(), start_index, end_index);
  }

  void update(int at, T value) {
    auto new_root = update_range_subroutine(root, 0, origin.size(), at, value);
    history.push_back(new_root);
    root = new_root;
  }
};
};  // namespace cpstl
