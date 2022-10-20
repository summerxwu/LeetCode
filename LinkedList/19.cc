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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *pre_node = new ListNode();
    ListNode *p1 = pre_node;
    ListNode *p2 = pre_node;
    while (n > 0) {
      p2 = p2->next;
      n--;
    }
    while (p2 != nullptr) {
      p2 = p2->next;
      p1 = p1->next;
    }
    ListNode *del = p1->next;
    if (del != nullptr) {
      p1->next = del->next;
    } else {
      p1->next = nullptr;
    }
    return pre_node->next;
  }
};
int main() { return 0; }
