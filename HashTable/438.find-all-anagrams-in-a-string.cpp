/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (48.95%)
 * Likes:    9005
 * Dislikes: 280
 * Total Accepted:    629.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given two strings s and p, return an array of all the start indices of p's
 * anagrams in s. You may return the answer in any order.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, p.length <= 3 * 10^4
 * s and p consist of lowercase English letters.
 *
 *
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isAnagrams(string s, int count[])
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            count[s[i] - 'a']--;
        }

        for (size_t i = 0; i < 26; i++)
        {
            if (count[i] != 0)
            {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p)
    {
        vector<int> result;
        if (s.size() < p.size())
        {
            return result;
        }

        size_t step = p.size();
        for (size_t i = step - 1; i < s.size(); i++)
        {
            int count[26] = {0};
            for (size_t i = 0; i < p.size(); i++)
            {
                count[p[i] - 'a']++;
            }
            size_t start = i - (step - 1);
            string sb_str = s.substr(start, step);
            if (this->isAnagrams(sb_str, count))
            {
                result.push_back(start);
            }
        }
        return result;
    }
};
// @lc code=end
