/*
 * @lc app=leetcode id=383 lang=c
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (57.63%)
 * Likes:    3258
 * Dislikes: 376
 * Total Accepted:    620.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '"a"\n"b"'
 *
 * Given two strings ransomNote and magazine, return true if ransomNote can be
 * constructed by using the letters from magazine and false otherwise.
 *
 * Each letter in magazine can only be used once in ransomNote.
 *
 *
 * Example 1:
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
 * Example 2:
 * Input: ransomNote = "aa", magazine = "ab"
 * Output: false
 * Example 3:
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote and magazine consist of lowercase English letters.
 *
 *
 */

// @lc code=start
#include <string.h>
bool canConstruct(char *ransomNote, char *magazine)
{
  size_t len_m = strlen(magazine);
  size_t len_r = strlen(ransomNote);
  if (len_r > len_m)
  {
    return false;
  }

  int count[26] = {0};
  for (size_t i = 0; i < len_m; i++)
  {
    count[magazine[i] - 'a']++;
    if (i < len_r)
    {
      count[ransomNote[i] - 'a']--;
    }
  }
  for (size_t i = 0; i < 26; i++)
  {
    if (count[i] < 0)
    {
      return false;
    }
  }
  return true;
}
// @lc code=end
