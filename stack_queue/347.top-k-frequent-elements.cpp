/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (64.81%)
 * Likes:    12117
 * Dislikes: 446
 * Total Accepted:    1.3M
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 *
 *
 *
 * Follow up: Your algorithm's time complexity must be better than O(n log n),
 * where n is the array's size.
 *
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // compute the frequence
    std::map<int, int> fc;
    for (size_t i = 0; i < nums.size(); i++) {
      auto iter = fc.find(nums[i]);
      if (iter != fc.end()) {
        int count = fc[nums[i]];
        fc[nums[i]] = ++count;
        continue;
      }
      fc[nums[i]] = 1;
    }
    // revert the value-frequency pair;
    std::multimap<int, int> cf;
    for (auto i = fc.begin(); i != fc.end(); i++) {
      cf.insert(std::pair<int, int>(i->second, i->first));
    }
    std::vector<int> rlt;
    auto iter = cf.end();
    for (size_t i = 0; i < k; i++) {
      rlt.push_back((--iter)->second);
    }
    return rlt;
  }
};
// @lc code=end
int main() {
  Solution s;
  std::vector<int> input = {1, 2};
  auto rlt = s.topKFrequent(input, 2);
  for (size_t i = 0; i < rlt.size(); i++) {
    cout << rlt[i] << endl;
  }
  return 0;
}