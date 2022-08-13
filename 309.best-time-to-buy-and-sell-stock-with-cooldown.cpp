/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> boughtStateProfit(n, 0), soldStateProfit(n, 0);
        boughtStateProfit[0] = -prices[0];
        soldStateProfit[0] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            // handling case where at current state, a person has a share
            boughtStateProfit[i] = max(boughtStateProfit[i - 1], (i - 2 >= 0 ? soldStateProfit[i - 2] : 0) - prices[i]);
            // handling case where at current state, a person doesn't has any share
            soldStateProfit[i] = max(soldStateProfit[i - 1], boughtStateProfit[i - 1] + prices[i]);
        }
        return soldStateProfit[n - 1];
    }
};
// @lc code=end
