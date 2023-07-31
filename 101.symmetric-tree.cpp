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
#include <assert.h>

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
  std::vector<int> flatternLeftTree(TreeNode *root) {
    // left -> right -> middel
    std::vector<int> left, right;
    if (root->left) {
      left = flatternLeftTree(root->left);
    } else {
      if (root->right) {
        left.push_back(-101);
      }
    }

    if (root->right) {
      right = flatternLeftTree(root->right);
    } else {
      if (root->left) {
        right.push_back(-101);
      }
    }

    left.insert(left.end(), right.begin(), right.end());
    left.push_back(root->val);

    return left;
  }
  std::vector<int> flatternRightTree(TreeNode *root) {
    // middel -> left -> right
    std::vector<int> left, right;
    if (root->left) {
      left = flatternRightTree(root->left);
    } else {
      if (root->right) {
        left.push_back(-101);
      }
    }

    if (root->right) {
      right = flatternRightTree(root->right);
    } else {
      if (root->left) {
        right.push_back(-101);
      }
    }

    std::vector<int> result;
    result.push_back(root->val);
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
  }
  std::vector<int> flatternTree(TreeNode *root) {
    std::vector<int> left_bound, right_bound;
    left_bound.clear();
    right_bound.clear();
    if (root->left) {
      left_bound = flatternLeftTree(root->left);
    } else {
      if (root->right) {
        left_bound.push_back(-101);
      }
    }

    if (root->right) {
      right_bound = flatternRightTree(root->right);
    } else {
      if (root->left) {
        right_bound.push_back(-101);
      }
    }

    left_bound.push_back(root->val);
    left_bound.insert(left_bound.end(), right_bound.begin(), right_bound.end());
    return left_bound;
  }
  bool isSymmetric(TreeNode *root) {
    // print the middle order sequence of the tree
    // then confirm that the seqence is symmetric or not
    std::vector<int> ft = flatternTree(root);
    int left = 0;
    int right = ft.size() - 1;
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
TreeNode *BuildTree(int input[], int size) {
  int size_save = size;
  TreeNode *root = new TreeNode();
  // build empty tree
  std::vector<TreeNode *> queue;
  queue.push_back(root);
  size--;
  int iter = -1;
  while (size > 0) {
    ++iter;
    TreeNode *i = queue[iter];
    if (!i->left) {
      i->left = new TreeNode();
      size--;
      queue.push_back(i->left);
      if (size <= 0) {
        break;
      }
    }
    if (!i->right) {
      i->right = new TreeNode();
      size--;
      queue.push_back(i->right);
      if (size <= 0) {
        break;
      }
    }
  }
  assert(queue.size() == size_save);
  // assign the value to the tree
  for (size_t i = 0; i < size_save; i++) {
    TreeNode *node = queue[i];
    node->val = input[i];
  }
  // print the Tree

  return root;
}

int main() {
  int valueList[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  TreeNode *tree = BuildTree(valueList, 10);
  return 0;
}