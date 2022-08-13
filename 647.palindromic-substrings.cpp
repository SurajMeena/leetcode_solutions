/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution
{
public:
    int recurse(string s, int start, int end, vector<vector<bool>> &visited)
    {
        visited[start][end] = true;
        if (start > end)
            return 0;
        if (s[start] == s[end])
        {
            if (!visited[start + 1][end - 1])
                return recurse(s, start + 1, end - 1, visited) + 1;
        }
        return (start + 1 < s.size() and end >= 0 and !visited[start + 1][end] ? recurse(s, start + 1, end, visited) : 0) + (start < s.size() and end - 1 >= 0 and !visited[start][end - 1] ? recurse(s, start, end - 1, visited) : 0);
    }
    int countSubstrings(string s)
    {
        vector<vector<bool>> visited(s.size(), vector<bool>(s.size(), false));
        return recurse(s, 0, s.size() - 1, visited);
    }
};
// @lc code=end
