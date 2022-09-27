/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

// @lc code=start
class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        string inputString = "";
        inputString = "L" + dominoes + "R";
        int left = 0, right = 1;
        while (right < inputString.size())
        {
            if (inputString[right] == 'L' or inputString[right] == 'R')
            {
                if (inputString[left] == inputString[right])
                {
                    left += 1;
                    while (left < right)
                    {
                        inputString[left] = inputString[right];
                        left++;
                    }
                }
                else if (inputString[left] == 'R' and inputString[right] == 'L')
                {
                    // In last submission there were separate conditions for odd and even number of digits between two indexes but that's not required and hence its removed here
                    int rightStop = left + (((right - left - 1) / 2) + 1), leftStop = right - (((right - left - 1) / 2) + 1);
                    int currleft = left, currright = right;
                    currleft += 1;
                    currright -= 1;
                    while (currleft < rightStop)
                    {
                        inputString[currleft++] = 'R';
                    }
                    while (currright > leftStop)
                    {
                        inputString[currright--] = 'L';
                    }
                }
                left = right;
            }
            right++;
        }
        return inputString.substr(1, dominoes.size());
    }
};
// @lc code=end
