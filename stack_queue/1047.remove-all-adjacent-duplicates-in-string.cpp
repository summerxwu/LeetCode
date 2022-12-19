/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 *
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
 *
 * algorithms
 * Easy (70.48%)
 * Likes:    5225
 * Dislikes: 204
 * Total Accepted:    411.2K
 * Total Submissions: 585.4K
 * Testcase Example:  '"abbaca"'
 *
 * You are given a string s consisting of lowercase English letters. A
 * duplicate removal consists of choosing two adjacent and equal letters and
 * removing them.
 *
 * We repeatedly make duplicate removals on s until we no longer can.
 *
 * Return the final string after all such duplicate removals have been made. It
 * can be proven that the answer is unique.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abbaca"
 * Output: "ca"
 * Explanation:
 * For example, in "abbaca" we could remove "bb" since the letters are adjacent
 * and equal, and this is the only possible move.  The result of this move is
 * that the string is "aaca", of which only "aa" is possible, so the final
 * string is "ca".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "azxxzy"
 * Output: "ay"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 *
 *
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  string removeDuplicates(string s) {
    for (size_t i = 0; i < s.size(); i++) {
      pushAndRemove(s[i]);
    }
    return buildStrFromStack();
  }

private:
  void pushAndRemove(char c) {
    if (_s.size() != 0 && c == _s.top()) {
      _s.pop();
      return;
    }
    _s.push(c);
  }
  std::string buildStrFromStack() {
    std::string result;
    auto count = _s.size();
    for (size_t i = 0; i < count; i++) {
      char c = _s.top();
      result.insert(0, std::string(1, c));
      _s.pop();
    }
    return result;
  }
  std::stack<char> _s;
};
// @lc code=end
int main() {
  Solution s;
  auto rlt = s.removeDuplicates("access");
  cout << rlt << endl;
}
