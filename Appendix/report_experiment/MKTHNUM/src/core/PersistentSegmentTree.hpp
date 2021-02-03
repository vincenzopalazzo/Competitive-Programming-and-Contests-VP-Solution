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
#include <memory>
#include <vector>

namespace cpstl {
template <typename T>
struct Node {
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;
  T value;

  Node(std::shared_ptr<Node> left, std::shared_ptr<Node> right, T value)
      : left(left), right(right), value(value) {}
  Node(T value) : left(nullptr), right(nullptr), value(value) {}
};

template <class T>
class PersistentSegmentTree {
 protected:
  std::size_t start_index;
  std::size_t end_index;
  std::vector<std::shared_ptr<Node<T>>> history;
  std::shared_ptr<Node<T>> empty_node;

  int range_query_subroutine(std::shared_ptr<Node<T>> &first_node,
                             std::shared_ptr<Node<T>> &second_node,
                             int left_index, int right_index, int target) {
    if (left_index == right_index) return left_index;

    auto middle_point = (left_index + right_index) / 2;
    auto left_count = second_node->left->value - first_node->left->value;
    if (left_count >= target)
      return range_query_subroutine(first_node->left, second_node->left,
                                    left_index, middle_point, target);
    return range_query_subroutine(first_node->right, second_node->right,
                                  middle_point + 1, right_index,
                                  target - left_count);
  }

  std::shared_ptr<Node<T>> update_range_subroutine(
      std::shared_ptr<Node<T>> &node, std::size_t left_index,
      std::size_t right_index, int pos, T value) {
    if (left_index > pos || right_index < pos) return node;
    if (left_index == right_index) {
      return std::make_shared<Node<T>>(this->empty_node, this->empty_node,
                                       node->value + value);
    }

    int middle_point = (left_index + right_index) / 2;
    auto left_node = update_range_subroutine(node->left, left_index,
                                             middle_point, pos, value);
    auto right_node = update_range_subroutine(node->right, middle_point + 1,
                                              right_index, pos, value);

    return std::make_shared<Node<T>>(left_node, right_node,
                                     node->value + value);
  }

 public:
  PersistentSegmentTree(std::size_t start, std::size_t end)
      : start_index(start), end_index(end) {
    this->empty_node = std::make_shared<Node<T>>(0);
    this->empty_node->left = this->empty_node;
    this->empty_node->right = this->empty_node;
    this->history.push_back(this->empty_node);
  }

  virtual ~PersistentSegmentTree() { history.clear(); }

  int range_query(std::size_t start_node, std::size_t end_node, T target) {
    return range_query_subroutine(this->history[start_node],
                                  this->history[end_node], this->start_index,
                                  this->end_index, target);
  }

  void update(std::size_t at, T value) {
    auto new_root = update_range_subroutine(
        this->history.back(), this->start_index, this->end_index, at, value);
    history.push_back(new_root);
  }
};
};  // namespace cpstl
