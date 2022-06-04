struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *cur = head;
    ListNode *pre = nullptr;
    while (cur != nullptr) {
      auto tmp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = tmp;
    }
    return cur;
  }

  ListNode *reverseRecursive(ListNode *head){
    if(head == nullptr || head->next == nullptr){
      return head;
    }
    ListNode * p = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
  }
};
int main() {}
