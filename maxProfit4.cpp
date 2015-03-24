/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include <iostream>
#include <vector>

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

        int **local = new int*[len + 1];
        int **global = new int*[len + 1];
        for( int i = 0; i <= len; ++i ){
        	local[i] = new int[k + 1];
        	global[i] = new int[k + 1];
        }

        for( int i = 0; i < len + 1; ++i ){
        	for( int j = 0; j < k + 1; ++j ){
        		local[i][j] = 0;
        		global[i][j] = 0;
        	}
        }

        for( int i = 2; i < len + 1; ++i ){
        	int diff = prices[i] - prices[i - 1];
        	for( int j = 1; j < k + 1; ++j ){
        		local[i][j] = max( global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff );
        		global[i][j] = max( local[i][j], global[i - 1][j] );
        	}
        }

        return global[len][k];
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

int main(){

	return 0;
}