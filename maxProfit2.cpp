//Say you have an array for which the ith element is the price of a given stock on day i.

//If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
#include <iostream>


using namespace std;

class Solution
{
public:
	int maxProfit(vector<int> &prices){
		int maxP = 0;

		for(int i = 0; i < int(prices.size())-1; i++){
			int diff = prices[i+1] - prices[i];
			if(diff <= 0) continue;

			maxP += diff;
		}

		return maxP;
	}
	
};