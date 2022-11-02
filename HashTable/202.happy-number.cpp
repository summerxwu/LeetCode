/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (54.35%)
 * Likes:    7160
 * Dislikes: 892
 * Total Accepted:    988.7K
 * Total Submissions: 1.8M
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number n is happy.
 *
 * A happy number is a number defined by the following process:
 *
 *
 * Starting with any positive integer, replace the number by the sum of the
 * squares of its digits.
 * Repeat the process until the number equals 1 (where it will stay), or it
 * loops endlessly in a cycle which does not include 1.
 * Those numbers for which this process ends in 1 are happy.
 *
 *
 * Return true if n is a happy number, and false if not.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 19
 * Output: true
 * Explanation:
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 *
 *
 * Example 2:
 *
 *
 * Input: n = 2
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int getNext(int n)
    {
        int total = 0;
        while (n != 0)
        {
            int tail = n - ((n / 10) * 10);
            total += tail * tail;
            n = n / 10;
        }
        return total;
    }
    bool isHappy(int n)
    {
        unordered_set<int> table;
        do
        {
            auto iter = table.find(n);
            if (iter != table.end())
            {
                return false;
            }
            else
            {
                table.insert(n);
            }
            n = this->getNext(n);
        } while (n != 1);
        return true;
    }
};
// @lc code=end
