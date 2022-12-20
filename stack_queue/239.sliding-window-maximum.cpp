/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (46.63%)
 * Likes:    13072
 * Dislikes: 427
 * Total Accepted:    701K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * You are given an array of integers nums, there is a sliding window of size k
 * which is moving from the very left of the array to the very right. You can
 * only see the k numbers in the window. Each time the sliding window moves
 * right by one position.
 *
 * Return the max sliding window.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation:
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 *
 *
 */

#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class SQueue {
public:
  SQueue() {}
  void Pop(int v) {
    if (_q.front() == v) {
      _q.pop_front();
    }
    return;
  }
  void Push(int v) {
    if (_q.size() == 0) {
      _q.push_back(v);
      return;
    }
    while (_q.size() != 0 && v > _q.back()) {
      _q.pop_back();
    }
    _q.push_back(v);
    return;
  }
  int max() { return _q.front(); }

private:
  std::deque<int> _q;
};
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int index = 0;
    SQueue sq;
    std::vector<int> rlt;
    for (size_t i = 0; i < k; i++) {
      sq.Push(nums[i]);
    }
    rlt.push_back(sq.max());
    index = k;
    for (size_t i = k; i < nums.size(); i++) {
      sq.Pop(nums[i - k]);
      sq.Push(nums[i]);
      rlt.push_back(sq.max());
    }
    return rlt;
  }
};
// @lc code=end
int main() {
  Solution s;
  std::vector<int> input = {1, 2};
  auto rlt = s.maxSlidingWindow(input, 2);
  for (size_t i = 0; i < rlt.size(); i++) {
    cout << rlt[i] << endl;
  }
  return 0;
}