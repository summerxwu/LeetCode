/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *new_pre = new ListNode();
    new_pre->next = head;
    ListNode *t = new_pre;
    ListNode *h = new_pre;
    if (head == nullptr || head->next == nullptr) {
      return nullptr;
    }
    while (true) {
      if (t->next == nullptr) {
        return nullptr;
      }
      t = t->next->next;
      h = h->next;
      if (t == h) {
        break;
      }
      if (t == nullptr || h == nullptr) {
        return nullptr;
      }
    }

    h = new_pre;
    while (true) {
      h = h->next;
      t = t->next;
      if (h == t) {
        return h;
      };
    }
    return nullptr;
  }
};
