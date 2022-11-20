/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (36.50%)
 * Likes:    8117
 * Dislikes: 945
 * Total Accepted:    675.6K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers, return an array of all the unique
 * quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 *
 *
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 *
 *
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,2,2,2,2], target = 8
 * Output: [[2,2,2,2]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 *
 *
 */

#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums, int target, int start) {
    vector<vector<int>> result;
    for (int i = start; i < (int)(nums.size() - 1); i++) {
      if (i > start && nums[i - 1] == nums[i]) {
        continue;
      }
      size_t left = i + 1;
      size_t right = nums.size() - 1;
      while (left < right) {
        long sum = (long)nums[i] + (long)nums[left] + (long)nums[right];
        if (sum < target) {
          left++;
        } else if (sum > target) {
          right--;
        } else {
          while (left < right && nums[left + 1] == nums[left]) {
            left++;
          }
          while (left < right && nums[right - 1] == nums[right]) {
            right--;
          }
          vector<int> item = {nums[i], nums[left], nums[right]};
          result.push_back(item);
          left++;
          right--;
        }
      }
    }
    return result;
  }

  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    for (int i = 0; i < (sz - 3); i++) {
      if (i > 0 && nums[i - 1] == nums[i]) {
        continue;
      }
      auto rt = this->threeSum(nums, target - nums[i], i + 1);
      for (int j = 0; j < rt.size(); j++) {
        auto item = rt[j];
        item.insert(item.begin(), nums[i]);
        result.push_back(item);
      }
    }
    return result;
  }
};
// @lc code=end
int main(int argc, char *argv[]) {
  vector<int> input = {1, 0, -1, 0, -2, 2};
  int target = 0;
  Solution s;
  auto result = s.fourSum(input, 0);
  return 0;
}
