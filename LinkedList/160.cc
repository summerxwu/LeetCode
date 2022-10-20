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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a_pre = new ListNode();
    a_pre->next = headA;
    ListNode *b_pre = new ListNode();
    b_pre->next = headB;
    ListNode *a = a_pre;
    ListNode *b = b_pre;
    while(a->next != b->next){
      a = a->next;
      b = b->next;
      if(a == nullptr){
        a = headB;
      }
      if(b == nullptr){
        b = headA;
      }
      if(a == nullptr && b == nullptr){
        return nullptr;
      }
    }
    return a->next;

  }
};
int main(){
  return 0;
}
