/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (32.26%)
 * Likes:    22328
 * Dislikes: 2044
 * Total Accepted:    2.3M
 * Total Submissions: 7.3M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not
 * matter.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stdio.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> distinct(vector<vector<int>> &input)
    {
        vector<vector<int>> result;
        unordered_map<string, vector<int>> hash;
        for (size_t i = 0; i < input.size(); i++)
        {
            string key;
            vector<int> item = input[i];
            for (size_t j = 0; j < item.size(); j++)
            {
                key.append("#");
                key.append(std::to_string(item[j]));
            }
            auto iter = hash.find(key);
            if (iter == hash.end())
            {
                hash[key] = item;
            }
        }
        auto iter = hash.begin();
        for (; iter != hash.end(); iter++)
        {
            result.push_back(iter->second);
        }
        return result;
    }
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        if (length < 3)
        {
            return result;
        }
        for (int i = 0; i < length - 2; i++)
        {
            int left = i + 1;
            int right = length - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                    continue;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                    continue;
                }
                else
                {
                    vector<int> v = {nums[i], nums[left], nums[right]};
                    result.push_back(v);
                    left++;
                    right--;
                }
            }
        }
        // distinct the result
        return this->distinct(result);
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<int> input = {-2, 0, 1, 1, 2};
    auto result = s.threeSum(input);
    printf("ab\n");
    return 0;
}
