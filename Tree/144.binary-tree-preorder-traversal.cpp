/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (64.63%)
 * Likes:    5488
 * Dislikes: 148
 * Total Accepted:    1.1M
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the preorder traversal of its nodes'
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [1,2,3]
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
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 *
 */

#include <iostream>
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
  vector<int> reCurpreorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return _rlt;
    }
    _rlt.push_back(root->val);
    this->preorderTraversal(root->left);
    this->preorderTraversal(root->right);
    return _rlt;
  }
  vector<int> preorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return _rlt;
    }
    _stack.push(root);
    while (_stack.size() != 0) {
      TreeNode *iter = _stack.top();
      _stack.pop();
      _rlt.push_back(iter->val);
      if (iter->right != nullptr) {
        _stack.push(iter->right);
      }
      if (iter->left != nullptr) {
        _stack.push(iter->left);
      }
    }
    return _rlt;
  }

private:
  std::vector<int> _rlt;
  std::stack<TreeNode *> _stack;
};
// @lc code=end