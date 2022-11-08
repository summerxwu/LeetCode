/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (30.28%)
 * Likes:    4263
 * Dislikes: 4221
 * Total Accepted:    791.8K
 * Total Submissions: 2.6M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string s, reverse the order of the words.
 *
 * A word is defined as a sequence of non-space characters. The words in s will
 * be separated by at least one space.
 *
 * Return a string of the words in reverse order concatenated by a single
 * space.
 *
 * Note that s may contain leading or trailing spaces or multiple spaces
 * between two words. The returned string should only have a single space
 * separating the words. Do not include any extra spaces.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "  hello world  "
 * Output: "world hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s contains English letters (upper-case and lower-case), digits, and spaces '
 * '.
 * There is at least one word in s.
 *
 *
 *
 * Follow-up: If the string data type is mutable in your language, can you
 * solve it in-place with O(1) extra space?
 *
 */

#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        // squash all the consecutive repeat space character
        size_t new_index = 0;
        size_t index = 0;
        for (; index < s.size(); index++)
        {
            if (new_index == 0 && s.at(index) == ' ')
            {
                continue;
            }
            if (s.at(index) == ' ' && (index + 1 == s.size() || s.at(index + 1) == ' '))
            {
                continue;
            }
            if (index != new_index)
            {
                s[new_index] = s.at(index);
            }
            new_index++;
        }
        s[new_index] = '\0';

        // reverse whole string
        s = s.c_str();
        size_t l = 0;
        size_t r = strlen(s.c_str()) - 1;
        while (l < r)
        {
            char t;
            t = s.at(r);
            s[r] = s[l];
            s[l] = t;
            l++;
            r--;
        }

        // reverse each word
        size_t w_s = 0;
        size_t w_e = 0;
        while (w_e < s.size())
        {
            while (w_e < s.size() && s.at(w_e) != ' ')
            {
                w_e++;
            }

            size_t l1 = w_s;
            size_t r1 = w_e - 1;
            while (l1 < r1)
            {
                char t;
                t = s.at(r1);
                s[r1] = s[l1];
                s[l1] = t;
                l1++;
                r1--;
            }
            w_s = w_e + 1;
            w_e++;
        }
        return s;
    }
};
// @lc code=end
int main()
{
    string input = "  summer is the   best  ";
    Solution s;
    s.reverseWords(input);
}
