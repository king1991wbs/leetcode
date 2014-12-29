//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
//Try to solve it in linear time/space.
//
//Return 0 if the array contains less than 2 elements.
//
//You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution{
public:
	int maximumGap(vector<int> &num){
		if(num.size() < 2) return 0;

		const int maxnumLen = 10;//最大数的长度位数
		vector<int> list[10];
		for(int i = 0; i < maxnumLen; ++i){
			for(int j = 0; j < num.size(); ++j){
				int index = int(num[j] / pow(10,i)) % 10;
				list[index].push_back(num[j]);
			}
			//num.clear();
			for(int index = 0, j = 0; index < 10; ++index){
				for(auto e : list[index])
					//num.insert(e);
					num[j++] = e;
				list[index].clear();
			}
		}

		//求最大差值
		int maxGap = abs(num[1] - num[0]);
		for(int j = 2; j < num.size(); ++j){
			int temp = abs(num[j] - num[j-1]);
			maxGap = temp > maxGap ? temp : maxGap;
		}

		return maxGap;
	}
};

int main(){
	vector<int> num = {1,2,4,5,6,73,4,6};
	Solution sol;
	cout << sol.maximumGap(num);
	return 0;
}
