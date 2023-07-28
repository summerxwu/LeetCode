/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (52.90%)
 * Likes:    11823
 * Dislikes: 265
 * Total Accepted:    1.5M
 * Total Submissions: 2.8M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given the root of a binary tree, check whether it is a mirror of itself
 * (i.e., symmetric around its center).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,2,3,4,4,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,2,null,3,null,3]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Could you solve it both recursively and iteratively?
 */
#include <vector>

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
class Solution {
 public:
  std::vector<int> flatternTree(TreeNode *root) {
    std::vector<int> left_bound, right_bound;
    if (root->left) {
      left_bound = flatternTree(root->left);
    }
    if (root->right) {
      right_bound = flatternTree(root->right);
    }

    left_bound.push_back(root->val);
    left_bound.insert(left_bound.end(), right_bound.begin(), right_bound.end());
    return left_bound;
  }
  bool isSymmetric(TreeNode *root) {
    // print the middle order sequence of the tree
    // then confirm that the seqence is symmetric or not
    std::vector<int> ft = flatternTree(root);
    size_t left = 0;
    size_t right = ft.size() - 1;
    while (left <= right) {
      if (ft[left] != ft[right]) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
};
// @lc code=end
