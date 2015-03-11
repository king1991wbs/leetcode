//Say you have an array for which the ith element is the price of a given stock on day i.

//Design an algorithm to find the maximum profit. You may complete at most two transactions.

//Note:
//You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> pre(prices.size(), 0);
        vector<int> post(prices.size(), 0);

        int maxP = 0;
        //pre
        int temp = 0;
        for(int i = 0; i < (int)prices.size()-1; ++i){
        	int diff = prices[i+1] - prices[i];
        	temp += diff;
        	if(temp < 0){
        		temp = 0;
        		//continue;
        	}
        	if(temp > maxP)
        		maxP = temp;
        	pre[i+1] = maxP;
        }
        //post
        maxP = 0;
        temp = 0;
        for(int j = (int)prices.size()-1; j > 0; --j){
        	int diff = prices[j] - prices[j-1];
        	temp += diff;
        	if(temp < 0){
        		temp = 0;
        		//continue;
        	}
        	if(temp > maxP)
        		maxP = temp;
        	post[j-1] = maxP;
        }
        maxP = 0;
        for(int k = 0; k < (int)prices.size()-1; ++k){
        	int temp = pre[k]+post[k];
        	if(temp > maxP)
        		maxP = temp;
        }

        return maxP;
    }
};

int main(){
	return 0;
}