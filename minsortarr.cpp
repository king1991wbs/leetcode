#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
    	if(num.empty()) return 0;
    	if(num.size() == 1) return *num.begin();
    	//only one element
    	//
		auto low = num.begin();
		auto high = num.end();
		high--;
		auto second = low + 1;
		//从小到大
		if(*low < *second && *second < *high) return *low;
		//if(*low > *second && *second > *high) return *high;

		if(*low > *high){
			while(++low <= --high && *low > *high);
			auto low_pre = --low;
			low++;
			auto high_next = ++high;
			high--;
			if(*low_pre > *low) return *low;
			if(*high > *high_next) return *high_next;
		}
	/*	if(*low < *high){
			while(++low <= --high && *low < *high);
			high = low;
			low--;
			return *low > *high ? *high : *low;
		}*/
		//只有两个元素且是有序的
		return *low;
    }
};


int main(){
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	Solution sol;
	sol.findMin(num);
	return 0;
}