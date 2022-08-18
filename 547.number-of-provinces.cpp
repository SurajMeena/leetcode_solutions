/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution
{
public:
    void dfs(vector<vector<int>> &isConnected, vector<int> &visited, int currNode)
    {
        visited[currNode] = 1;
        for (int i = 0; i < isConnected[currNode].size(); i++)
        {
            if (isConnected[currNode][i] and !visited[i])
                dfs(isConnected, visited, i);
        }
        return;
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // let's create adjancency matrix based on the input
        int possibleNodes = isConnected.size();
        vector<int> visited(possibleNodes, 0);
        int countProvinces = 0;
        for (int i = 0; i < possibleNodes; i++)
        {
            if (!visited[i])
            {
                dfs(isConnected, visited, i);
                countProvinces++;
            }
        }
        return countProvinces;
    }
};
// @lc code=end
