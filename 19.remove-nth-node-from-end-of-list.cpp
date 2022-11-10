/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (39.93%)
 * Likes:    13729
 * Dislikes: 568
 * Total Accepted:    1.8M
 * Total Submissions: 4.4M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1], n = 1
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
 *
 *
 * Follow up: Could you do this in one pass?
 *
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution
{
public:
    void removeSingleNode(ListNode *prev)
    {
        if (prev->next != nullptr)
        {
            prev->next = prev->next->next;
        }
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head->next == nullptr)
        {
            return nullptr;
        }
        ListNode *l = head;
        ListNode *r = head;

        while (r->next)
        {
            if (n > 0)
            {
                r = r->next;
                n--;
                continue;
            }
            r = r->next;
            l = l->next;
        }
        this->removeSingleNode(l);
        return head;
    }
};
// @lc code=end
