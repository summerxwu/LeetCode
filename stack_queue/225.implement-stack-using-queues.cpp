/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 *
 * https://leetcode.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (57.51%)
 * Likes:    3822
 * Dislikes: 941
 * Total Accepted:    409.9K
 * Total Submissions: 707.7K
 * Testcase Example:
 * '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * Implement a last-in-first-out (LIFO) stack using only two queues. The
 * implemented stack should support all the functions of a normal stack (push,
 * top, pop, and empty).
 *
 * Implement the MyStack class:
 *
 *
 * void push(int x) Pushes element x to the top of the stack.
 * int pop() Removes the element on the top of the stack and returns it.
 * int top() Returns the element on the top of the stack.
 * boolean empty() Returns true if the stack is empty, false otherwise.
 *
 *
 * Notes:
 *
 *
 * You must use only standard operations of a queue, which means that only push
 * to back, peek/pop from front, size and is empty operations are valid.
 * Depending on your language, the queue may not be supported natively. You may
 * simulate a queue using a list or deque (double-ended queue) as long as you
 * use only a queue's standard operations.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["MyStack", "push", "push", "top", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * Output
 * [null, null, null, 2, 2, false]
 *
 * Explanation
 * MyStack myStack = new MyStack();
 * myStack.push(1);
 * myStack.push(2);
 * myStack.top(); // return 2
 * myStack.pop(); // return 2
 * myStack.empty(); // return False
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= x <= 9
 * At most 100 calls will be made to push, pop, top, and empty.
 * All the calls to pop and top are valid.
 *
 *
 *
 * Follow-up: Can you implement the stack using only one queue?
 *
 */

#include <iostream>
#include <queue>
using namespace std;
// @lc code=start
class MyStack {
public:
  MyStack() {}

  void push(int x) {
    auto q = _q1.size() > 0 ? &_q1 : &_q2;
    q->push(x);
  }

  int pop() {
    if (_q1.size() != 0) {
      tranverse(_q1, _q2);
      auto item = _q1.front();
      _q1.pop();
      return item;
    }
    tranverse(_q2, _q1);
    auto item = _q2.front();
    _q2.pop();
    return item;
  }

  int top() {
    if (_q1.size() != 0) {
      return _q1.back();
    }
    return _q2.back();
  }

  bool empty() { return _q1.empty() && _q2.empty(); }

private:
  void tranverse(std::queue<int> &from, std::queue<int> &to) {
    size_t count = from.size();
    for (size_t i = 0; i < count - 1; i++) {
      auto item = from.front();
      to.push(item);
      from.pop();
    }
  }
  std::queue<int> _q1;
  std::queue<int> _q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main() {

  MyStack *obj = new MyStack();
  obj->push(1);
  obj->push(2);
  int param_2 = obj->pop();
  int param_3 = obj->top();
  bool param_4 = obj->empty();
  cout << param_2 << " " << param_3 << " " << param_4 << " " << endl;
}