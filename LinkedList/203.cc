#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    auto newHead = new ListNode(-1, nullptr);
    newHead->next = head;
    auto p = newHead;
    while (p->next != nullptr) {
      auto iter = p->next;
      if (iter->val == val) {
        // delete
        p->next = iter->next;
      }
      else{
        p = p->next;
      }
    }
    return newHead->next;
  }
};

ListNode *construct(vector<int> &input) {
  if (input.size() == 0) {
    return nullptr;
  }
  auto iter = new ListNode(input[0], nullptr);
  auto pr = iter;
  for (int i = 1; i < input.size(); i++) {
    auto it = new ListNode(input[i], nullptr);
    pr->next = it;
    pr = pr->next;
  }
  return iter;
}
void PrintList(ListNode *head) {
  auto it = head;
  while (it != nullptr) {
    cout << it->val;
    cout << endl;
    it = it->next;
  }
}

int main() {

  vector<int> input = { 1, 2, 6, 3, 4, 5, 6 };
  auto list = construct(input);
  Solution s;
  auto relt = s.removeElements(list, 6);
  PrintList(relt);
  return 0;
}
