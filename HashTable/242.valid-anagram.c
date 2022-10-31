/*
 * @lc app=leetcode id=242 lang=c
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (62.72%)
 * Likes:    7356
 * Dislikes: 244
 * Total Accepted:    1.8M
 * Total Submissions: 2.8M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 *
 *
 *
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 *
 */

// @lc code=start
#include <string.h>
bool isAnagram(char *s, char *t)
{
  int A[26] = {0}, slen = strlen(s);
  if (slen != strlen(t))
    return false;
  for (int i = 0; i < slen; A[s[i] - 'a']++, A[t[i] - 'a']--, i++)
    ;
  for (int i = 0; i < 26; i++)
    if (A[i])
      return false;
  return true;
  // if (strlen(s) != strlen(t))
  //{
  //   return false;
  // }
  // int count[26] = {0};
  // for (size_t i = 0; i < strlen(s); count[(s[i] - 'a')]++, count[(t[i] - 'a')]--, i++)
  //   ;
  // for (size_t i = 0; i < 26; i++)
  //{
  //   if (count[i])
  //   {
  //     return false;
  //   }
  // }

  // return true;
}
// @lc code=end
