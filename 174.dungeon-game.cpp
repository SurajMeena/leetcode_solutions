/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = dungeon[0][0];
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = dp[i - 1][0] + dungeon[i][0];
        }
        for (int j = 1; j < n; j++)
        {
            dp[0][j] = dp[0][j - 1] + dungeon[0][j];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (dp[i - 1][j] + dungeon[i][j] >= 0 or dp[i][j - 1] + dungeon[i][j] >= 0)
                    dp[i][j] = min(dp[i - 1][j] + dungeon[i][j], dp[i][j - 1] + dungeon[i][j]);
                else
                    dp[i][j] = max(dp[i - 1][j] + dungeon[i][j], dp[i][j - 1] + dungeon[i][j]);
            }
        }
        if (dp[m - 1][n - 1] >= 0)
            return 1;
        else
            return -(dp[m - 1][n - 1] - 1);
    }
};

// @lc code=end
