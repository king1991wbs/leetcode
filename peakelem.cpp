//A peak element is an element that is greater than its neighbors.
//
//Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.
//
//The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
//You may imagine that num[-1] = num[n] = -¡Þ.
//
//For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	int findPeakElement(const vector<int> &num){
		if(num.size() <= 1) return 0;
		if(num[0] > num[1]) return 0;
		for(int i = 1; i < num.size() - 1; ++i){
			if(num[i] > num[i-1] && num[i] > num[i+1])
				return i;
		}

		if(num[num.size()-1] > num[num.size()-2]) return num.size()-1;
		return 0;
	}
};

int main(){
	vector<int> num = {2,1};
	Solution sol;
	cout << sol.findPeakElement(num);
}
