/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution
{
public:
    int ans = 0;
    int getMax(vector<vector<char>> &matrix, int i, int j, vector<vector<int>> &memo)
    {
        if (i >= matrix.size() or j >= matrix[0].size())
            return 0;
        if (memo[i][j] == -1)
        {
            // always calling temp because you want to recurse for whole tree no matter what, relevant results you can return for current element
            int temp = min({getMax(matrix, i + 1, j, memo), getMax(matrix, i, j + 1, memo), getMax(matrix, i + 1, j + 1, memo)}) + 1;
            if (matrix[i][j] == '0')
            {
                memo[i][j] = 0;
                return 0;
            }
            ans = max(ans, temp);
            return memo[i][j] = temp;
        }
        return memo[i][j];
    }
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        getMax(matrix, 0, 0, memo);
        return ans * ans;
    }
};
// @lc code=end
