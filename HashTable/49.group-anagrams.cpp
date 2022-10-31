/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (66.39%)
 * Likes:    13068
 * Dislikes: 388
 * Total Accepted:    1.7M
 * Total Submissions: 2.6M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 *
 *
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution
{
public:
    std::string genKey(std::string &str)
    {
        int count[26] = {0};
        const char *str_c = str.c_str();
        for (size_t i = 0; i < str.length(); i++)
        {
            count[str_c[i] - 'a']++;
        }
        std::string key;
        for (size_t i = 0; i < 26; i++)
        {
            std::string f = std::to_string(count[i]);
            key.append(f);
            key.append("#");
        }
        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> result;
        for (auto &&str : strs)
        {
            auto key = this->genKey(str);
            auto iter = result.find(key);
            if (iter != result.end())
            {
                iter->second.push_back(str);
            }
            else
            {
                vector<string> item;
                item.push_back(str);
                result[key] = item;
            }
        }
        vector<vector<string>> fresult;
        for (auto iter = result.begin(); iter != result.end(); iter++)
        {
            fresult.push_back(iter->second);
        }
        return fresult;
    }
};
// @lc code=end
