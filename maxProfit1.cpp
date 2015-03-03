//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	int maxProfit(vector<int> &prices){

		int profit = 0;
		int maxP = 0;
		int eleSize = prices.size();//size()函数返回的值是无符号整形，因此直接用在for循环prices.szie()-1下溢
		for(int i = 0; i < eleSize - 1; ++i){
			profit += prices[i+1] - prices[i];
			if(profit <= 0){
				profit = 0;
				continue;
			}
			maxP = max(maxP, profit);
		}

		return maxP;
	}
};
int main(){
	vector<int> prices;
	Solution sol;
	cout << sol.maxProfit(prices);
}
