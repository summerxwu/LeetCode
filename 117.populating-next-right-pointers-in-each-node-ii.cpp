/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (49.68%)
 * Likes:    5027
 * Dislikes: 292
 * Total Accepted:    528.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5,null,7]'
 *
 * Given a binary tree
 *
 *
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 *
 *
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,4,5,null,7]
 * Output: [1,#,2,3,#,4,5,7,#]
 * Explanation: Given the above binary tree (Figure A), your function should
 * populate each next pointer to point to its next right node, just like in
 * Figure B. The serialized output is in level order as connected by the next
 * pointers, with '#' signifying the end of each level.
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 6000].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow-up:
 *
 *
 * You may only use constant extra space.
 * The recursive approach is fine. You may assume implicit stack space does not
 * count as extra space for this problem.
 *
 *
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
 public:
  Node* connect(Node* root) {
    if (root == nullptr) {
      return nullptr;
    }
    queue<Node*> _queue;
    _queue.push(root);
    while (!_queue.empty()) {
      size_t num = _queue.size();
      vector<Node*> vec;
      for (size_t i = 0; i < num; i++) {
        Node* item = _queue.front();
        if (item->left) _queue.push(item->left);
        if (item->right) _queue.push(item->right);
        vec.push_back(item);
        _queue.pop();
      }
      // populate the next pointer of Node Which stored in the vec
      for (size_t i = 0; i < vec.size(); i++) {
        if (i == vec.size() - 1) {
          vec[i]->next = nullptr;
        } else {
          vec[i]->next = vec[i + 1];
        }
      }
    }
    return root;
  }
};
// @lc code=end
