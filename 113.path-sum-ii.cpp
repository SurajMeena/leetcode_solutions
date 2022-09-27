/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void traverseTree(vector<int> temp, TreeNode *root, vector<vector<int>> &ans, int targetSum)
    {
        if (root == NULL)
            return;
        temp.push_back(root->val);
        // root->left and root->right can only be equal if they are both null
        if ((root->left == root->right) and (targetSum - root->val == 0))
            ans.push_back(temp);
        else
        {
            traverseTree(temp, root->left, ans, targetSum - root->val);
            traverseTree(temp, root->right, ans, targetSum - root->val);
        }
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        traverseTree(temp, root, ans, targetSum);
        return ans;
    }
};
// @lc code=end
