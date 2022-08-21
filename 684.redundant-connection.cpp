/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
class Solution
{
public:
    // we will be using union by rank and find using path compression
    int findSet(int vertex, vector<pair<int, int>> &disjointArr)
    {
        if (disjointArr[vertex].first == -1)
            return vertex;
        return disjointArr[vertex].first = findSet(disjointArr[vertex].first, disjointArr);
    }
    void unionSet(int parentA, int parentB, vector<pair<int, int>> &disjointArr)
    {
        // pair<int,int> nodeA = findSet(vertexA);
        // pair<int,int> nodeB = findSet(vertexB);
        if (disjointArr[parentA].second > disjointArr[parentB].second)
            disjointArr[parentB].first = parentA;
        else if (disjointArr[parentA].second < disjointArr[parentB].second)
            disjointArr[parentA].first = parentB;
        else
        {
            disjointArr[parentA].first = parentB;
            disjointArr[parentB].second = disjointArr[parentB].second + 1;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<pair<int, int>> disjointArr(1001, make_pair(-1, 0));
        for (int i = 0; i < edges.size(); i++)
        {
            int nodeA = findSet(edges[i][0], disjointArr);
            int nodeB = findSet(edges[i][1], disjointArr);
            if (nodeA == nodeB)
                return {edges[i][0], edges[i][1]};
            else
            {
                unionSet(nodeA, nodeB, disjointArr);
            }
        }
        return {};
    }
};
// @lc code=end
