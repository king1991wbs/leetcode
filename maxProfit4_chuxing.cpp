/*****************************************************************
    *  @Author   : 楚兴
    *  @Date     : 2015/2/22 23:42
    *  @Status   : Accepted
    *  @Runtime  : 15 ms
******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int len = prices.size();
        if (len == 0)
        {
            return 0;
        }
        if (k >= len)
        {
            return helper(prices);
        }

        vector<int> max_local(k + 1, 0);
        vector<int> max_global(k + 1, 0);
        int diff;
        for (int i = 0; i < len - 1; i++)
        {
            diff = prices[i + 1] - prices[i];
            for (int j = k; j >= 1; j--)
            {
                max_local[j] = max(max_global[j - 1] + max(diff, 0), max_local[j] + diff);
                max_global[j] = max(max_local[j], max_global[j]);
            }
        }

        return max_global[k];
    }

    int helper(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            profit = max(profit, profit + prices[i + 1] - prices[i]);
        }

        return profit;
    }
};