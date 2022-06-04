/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *pre_head = new ListNode();
    pre_head->next = head;
    ListNode *prev = pre_head;
    ListNode *curr = head;
    while (curr != nullptr && curr->next != nullptr) {
      ListNode *nt = curr->next;
      curr->next = nt->next;
      nt->next = curr;
      prev->next = nt;
      prev = curr;
      curr = curr->next;
    }
    return pre_head->next;
  }
};
