/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (50.50%)
 * Likes:    1315
 * Dislikes: 2829
 * Total Accepted:    176.2K
 * Total Submissions: 348.8K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * Given a string s and an integer k, reverse the first k characters for every
 * 2k characters counting from the start of the string.
 *
 * If there are fewer than k characters left, reverse all of them. If there are
 * less than 2k but greater than or equal to k characters, then reverse the
 * first k characters and leave the other as original.
 *
 *
 * Example 1:
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * Example 2:
 * Input: s = "abcd", k = 2
 * Output: "bacd"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of only lowercase English letters.
 * 1 <= k <= 10^4
 *
 *
 */

#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseRange(string &s, size_t start, size_t end, int k)
    {
        size_t r_start = start;

        size_t r_end = 0;
        if (end - start + 1 <= k)
        {
            r_end = end;
        }
        else if (k < end - start + 1 && end - start + 1 <= 2 * k)
        {
            r_end = start + k - 1;
        }
        else
        {
            return s;
        }
        while (r_start < r_end)
        {
            char t;
            t = s.at(r_end);
            s[r_end] = s.at(r_start);
            s[r_start] = t;
            r_start++;
            r_end--;
        }
        return s;
    }

    string reverseStr(string s, int k)
    {
        string result = s;
        if (s.size() <= 2 * k)
        {
            return this->reverseRange(result, 0, s.size() - 1, k);
        }
        size_t i = 0;
        for (; i + 2 * k < s.size(); i = i + 2 * k)
        {
            this->reverseRange(result, i, i + 2 * k - 1, k);
        }
        return this->reverseRange(result, i, s.size() - 1, k);
    }
};
// @lc code=end
int main()
{
    Solution s;
    string input = "abcedfghi";
    s.reverseStr(input, 2);
}
