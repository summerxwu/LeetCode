/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (66.59%)
 * Likes:    5357
 * Dislikes: 161
 * Total Accepted:    874.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the postorder traversal of its
 * nodes' values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [3,2,1]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of the nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<int> _postorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return _rlt;
    }
    this->postorderTraversal(root->left);
    this->postorderTraversal(root->right);
    _rlt.push_back(root->val);
    return _rlt;
  }
  // Iterate approch
  vector<int> __postorderTraversal(TreeNode *root) {
    if (root == NULL) {
      return _rlt;
    }
    _stack.push(root);
    while (_stack.size() != 0) {
      TreeNode *iter = _stack.top();
      _rlt.push_back(iter->val);
      _stack.pop();
      if (iter->left != NULL) {
        _stack.push(iter->left);
      }
      if (iter->right != NULL) {
        _stack.push(iter->right);
      }
    }
    std::reverse(_rlt.begin(), _rlt.end());
    return _rlt;
  }
  // Iterate approch
  vector<int> postorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return _rlt;
    }
    _stack.push(root);
    while (_stack.size()) {
      TreeNode *iter = _stack.top();
      if (iter->left != nullptr) {
        _stack.push(iter->left);
        iter->left = nullptr;
        continue;
      }
      if (iter->right != nullptr) {
        _stack.push(iter->right);
        iter->right = nullptr;
        continue;
      }
      _stack.pop();
      _rlt.push_back(iter->val);
    }
    return _rlt;
  }

 private:
  vector<int> _rlt;
  std::stack<TreeNode *> _stack;
};
// @lc code=end
