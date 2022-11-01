/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 *
 * https://leetcode.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (68.31%)
 * Likes:    2681
 * Dislikes: 221
 * Total Accepted:    161.9K
 * Total Submissions: 237K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * Given a string array words, return an array of all characters that show up
 * in all strings within the words (including duplicates). You may return the
 * answer in any order.
 *
 *
 * Example 1:
 * Input: words = ["bella","label","roller"]
 * Output: ["e","l","l"]
 * Example 2:
 * Input: words = ["cool","lock","cook"]
 * Output: ["c","o"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 100
 * words[i] consists of lowercase English letters.
 *
 *
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<string> result;
        size_t words_count = words.size();
        int **statistics = new int *[words_count];
        for (size_t i = 0; i < words_count; i++)
        {
            statistics[i] = new int[26];
            memset(statistics[i], 0, 26 * sizeof(int));
        }
        for (size_t i = 0; i < words_count; i++)
        {
            string p = words[i];
            int *s = statistics[i];
            for (size_t j = 0; j < p.size(); j++)
            {
                s[p.at(j) - 'a']++;
            }
        }
        int min_count[26] = {100};
        for (size_t i = 0; i < 26; i++)
        {
            min_count[i] = 100;
        }

        for (size_t i = 0; i < words_count; i++)
        {
            int *s = statistics[i];
            for (size_t j = 0; j < 26; j++)
            {
                if (s[j] < min_count[j])
                {
                    min_count[j] = s[j];
                }
            }
        }
        for (size_t i = 0; i < 26; i++)
        {
            int count = min_count[i];
            if (count > 0)
            {
                while (count > 0)
                {
                    string item(1, 'a' + i);
                    result.push_back(item);
                    count--;
                }
            }
        }
        return result;
    }
};
// @lc code=end
