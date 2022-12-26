/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (72.97%)
 * Likes:    10411
 * Dislikes: 493
 * Total Accepted:    1.8M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
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
  vector<int> _inorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return _rlt;
    }
    this->inorderTraversal(root->left);
    _rlt.push_back(root->val);
    this->inorderTraversal(root->right);
    return _rlt;
  }

  vector<int> __inorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return _rlt;
    }
    _stack.push(root);
    while (_stack.size()) {
      TreeNode *iter = _stack.top();
      if (iter->left != nullptr) {
        _stack.push(iter->left);
        // because of the recalling of the node, the left pt need to be set
        // null.
        iter->left = nullptr;
        continue;
      } else {
        _rlt.push_back(iter->val);
        _stack.pop();
        if (iter->right != nullptr) {
          _stack.push(iter->right);
          iter->right = nullptr;
        }
      }
    }
    return _rlt;
  }

 private:
  vector<int> _rlt;
  stack<TreeNode *> _stack;
};
// @lc code=end
