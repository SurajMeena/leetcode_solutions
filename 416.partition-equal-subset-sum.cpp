/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution
{
public:
    bool recurse(int currSum, int currInd, vector<int> &nums, int totalSum)
    {
        if (totalSum - currSum == currSum)
        {
            // cout << currSum << " Here it got returned true" << endl;
            return true;
        }
        else if (currInd >= nums.size())
        {
            // cout << currInd << " " << nums.size() << endl;
            // cout << currSum << " Here it exceeded arr length" << endl;
            return false;
        }
        // else
        // cout << currSum << endl;
        for (int i = currInd; i < nums.size(); i++)
        {
            if (recurse(currSum + nums[i], i + 1, nums, totalSum) or recurse(currSum, i + 1, nums, totalSum))
                return true;
        }
        return false;
    }
    bool canPartition(vector<int> &nums)
    {
        // try to form all possible combinations through recursion
        // and keep track of their sum rather than the combination itself
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        return recurse(0, 0, nums, totalSum);
    }
};
// @lc code=end
