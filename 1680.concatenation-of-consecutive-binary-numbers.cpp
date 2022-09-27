/*
 * @lc app=leetcode id=1680 lang=cpp
 *
 * [1680] Concatenation of Consecutive Binary Numbers
 */

// @lc code=start
class Solution
{
public:
    int concatenatedBinary(int n)
    {
        // iterative solution using bit manipulation but same logic
        long ans = 0, leftShift = 0, MOD = 1e9 + 7;
        for (int i = 1; i <= n; i++)
        {
            if ((i & i - 1) == 0)
                leftShift++;
            ans = ((ans << leftShift) | i) % MOD;
        }
        return ans;
    }
};
// @lc code=end
