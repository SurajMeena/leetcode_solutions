/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
#define modulo 1000000007
class Solution
{
public:
    int rowDir[4] = {0, 1, 0, -1};
    int colDir[4] = {1, 0, -1, 0};
    int dp[51][51][51];
    int recurse(int i, int j, int moves, int m, int n, int maxMove)
    {
        if ((i >= m or j >= n or i < 0 or j < 0) and moves <= maxMove)
        {
            return 1;
        }
        else if (moves > maxMove)
            return 0;
        if (dp[i][j][moves] != -1)
            return dp[i][j][moves];
        int count = 0;
        for (int k = 0; k < 4; k++)
        {
            count = (count + recurse(i + rowDir[k], j + colDir[k], moves + 1, m, n, maxMove)) % modulo;
        }
        return dp[i][j][moves] = count;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        return recurse(startRow, startColumn, 0, m, n, maxMove);
    }
};
// @lc code=end
