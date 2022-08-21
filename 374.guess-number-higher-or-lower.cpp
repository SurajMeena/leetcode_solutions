/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        // clearly a binary search problem
        // let's run binary search for range[1,n];
        int start = 1, end = n;
        int mid;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (guess(mid) == 0)
                return mid;
            else if (guess(mid) == 1)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return mid;
    }
};
// @lc code=end
