/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (70.23%)
 * Likes:    3859
 * Dislikes: 2021
 * Total Accepted:    763.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two integer arrays nums1 and nums2, return an array of their
 * intersection. Each element in the result must be unique and you may return
 * the result in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * Explanation: [4,9] is also accepted.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 *
 *
 */

// @lc code=start
#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> result;
        unordered_set<int> hash_table;
        for (size_t i = 0; i < nums1.size(); i++)
        { /* code */
            hash_table.insert(nums1[i]);
        }
        for (size_t i = 0; i < nums2.size(); i++)
        {
            auto iter = hash_table.find(nums2[i]);
            if (iter != hash_table.end())
            {
                result.insert(nums2[i]);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};
// @lc code=end
