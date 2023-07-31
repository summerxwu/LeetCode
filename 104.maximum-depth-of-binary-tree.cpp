/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (74.10%)
 * Likes:    11386
 * Dislikes: 187
 * Total Accepted:    2.5M
 * Total Submissions: 3.3M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return its maximum depth.
 *
 * A binary tree's maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 3
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,null,2]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -100 <= Node.val <= 100
 *
 *
 */

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
  int treeDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int leftDepth, rightDepth;
    if (root->left) {
      leftDepth = treeDepth(root->left);
    } else {
      leftDepth = 0;
    }
    if (root->right) {
      rightDepth = treeDepth(root->right);
    } else {
      rightDepth = 0;
    }
    int maxOne = leftDepth > rightDepth ? leftDepth : rightDepth;
    return maxOne + 1;
  }
  int maxDepth(TreeNode *root) {
    // recursive way to evaluate the right subtree and left subtree depth,
    // choose the bigger one as the finial after plusing one
    return treeDepth(root);
  }
};
// @lc code=end
