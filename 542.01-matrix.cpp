/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution
{
public:
    int rowDir[4] = {0, 1, 0, -1};
    int colDir[4] = {1, 0, -1, 0};

    bool isValidCell(int i, int j, int m, int n, vector<vector<int>> &visited)
    {
        if ((i >= m or j >= n or i < 0 or j < 0) or visited[i][j])
            return false;
        return true;
    }
    int dfs(int i, int j, vector<vector<int>> mat, vector<vector<int>> &visited, vector<vector<int>> &ans)
    {
        if (isValidCell(i, j, mat.size(), mat[0].size(), visited) and mat[i][j] == 0)
            return ans[i][j] = 0;
        else if (!isValidCell(i, j, mat.size(), mat[0].size(), visited))
            return 10001;
        visited[i][j] = 1;
        int dist = 10001;
        for (int k = 0; k < 4; k++)
        {
            dist = min(dist, (ans[i][j] == -1 ? dfs(i + rowDir[k], j + colDir[k], mat, visited, ans) : ans[i][j]) + 1);
        }
        visited[i][j] = 0;
        return ans[i][j] = dist;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), -1));
        vector<vector<int>> visited(mat.size(), vector<int>(mat[0].size(), 0));
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (ans[i][j] == -1)
                    dfs(i, j, mat, visited, ans);
            }
        }
        return ans;
    }
};
// @lc code=end
