#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
	int findMin(vector<int> &num){
		int n = num.size();
		if(n == 0)
			return 0;
		if(n == 1)
			return num[0];

		int i = 0, j = n - 1;
		int minimum = num[0];
		while(i <= j){
			minimum = min(minimum, min(num[i], num[j]));

			if(num[i + 1] >= num[i]) 
				++i;
			else
				return num[i + 1];
			if(num[j - 1] <= num[j])
				--j;
			else
				return num[j];
		}
		return minimum;
	}
};


int main(){
	vector<int> num = {1,2,3,4,5,6};

	Solution sol;
	cout << sol.findMin(num);
}
