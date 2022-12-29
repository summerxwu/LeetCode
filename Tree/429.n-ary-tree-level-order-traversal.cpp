/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (70.58%)
 * Likes:    3216
 * Dislikes: 125
 * Total Accepted:    266.7K
 * Total Submissions: 377.6K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * Given an n-ary tree, return the level order traversal of its nodes' values.
 *
 * Nary-Tree input serialization is represented in their level order traversal,
 * each group of children is separated by the null value (See examples).
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: root = [1,null,3,2,4,null,5,6]
 * Output: [[1],[3,2,4],[5,6]]
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
 *
 *
 *
 * Constraints:
 *
 *
 * The height of the n-ary tree is less than or equal to 1000
 * The total number of nodes is between [0, 10^4]
 *
 *
 */

#include <queue>
#include <vector>
using namespace std;
class Node {
 public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
 public:
  void appendChild(Node *node, queue<Node *> &_queue) {
    size_t num = node->children.size();
    if (num != 0) {
      for (size_t i = 0; i < num; i++) {
        _queue.push(node->children[i]);
      }
    }
    return;
  }
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> result;
    if (root == nullptr) {
      return result;
    }
    queue<Node *> _queue;
    _queue.push(root);
    while (!_queue.empty()) {
      size_t num = _queue.size();
      vector<int> item;
      for (size_t i = 0; i < num; i++) {
        Node *p = _queue.front();
        this->appendChild(p, _queue);
        item.push_back(p->val);
        _queue.pop();
      }
      result.push_back(item);
    }
    return result;
  }
};
// @lc code=end
