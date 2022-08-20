/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i][0] = 1;
        }
        for (int j = 1; j < target; j++)
        {
            dp[0][j] = false;
        }
        for (int i = 1; i <= nums.size(); i++)
        {
            for (int j = 1; j <= target; j++)
            {
                if (nums[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[nums.size()][target];
    }
};
// @lc code=end
