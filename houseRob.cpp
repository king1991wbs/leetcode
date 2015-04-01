/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
    	if(num.size() == 0)
    		return 0;

        vector<int> maxRobI(num.size(), -1);
        return maxMoney(num, 0, maxRobI);
    }
private:
	int maxMoney(const vector<int> &num, const int i, vector<int> &maxRobI){
		if(maxRobI[i] != -1)
			return maxRobI[i];
		if(i == num.size() - 1)
			return num[i];
		if(i == num.size() - 2)
			return max(num[i], num[i + 1]);

		maxRobI[i] = max(num[i] + maxMoney(num, i + 2, maxRobI), maxMoney(num, i + 1, maxRobI));

		return maxRobI[i];
	}
};

int main(int argc, char const *argv[])
{
	vector<int> num = {1,2,3,4};
	Solution sol;
	sol.rob(num);
	return 0;
}