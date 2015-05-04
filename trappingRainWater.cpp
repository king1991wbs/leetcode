/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if( height.size() < 3 )
        	return 0;
        int sum = 0;
        int first = 0, next = 0;
        int maxIdx = 0;
       	maxIdx = first + 1;
       	next = maxIdx;
        while( first <= (height.size() - 1) ){
        	while(next != height.size()){
        		maxIdx = height[maxIdx] > height[next] ? maxIdx : next;
        		if( height[maxIdx] > height[first] )
        			break;
        		next++;
        	}
        	sum += trapWater(first, maxIdx, height);
        	if( maxIdx == height.size()-1 )
        		return sum;
        	first = maxIdx;
        	maxIdx++;
        	next = maxIdx;
        }
        
    }

    int trapWater(int chg1, int chg2, const vector<int>& height){
    	int tem = min(height[chg1], height[chg2]);
    	int s = 0;
    	while( chg1 <= chg2 ){
    		s += max(tem - height[chg1], 0);
    		chg1++;
    	}
    	return s;
    }
};

int main(){
	vector<int> height = {5,2,1,2,1,5};
	Solution sol;
	cout << sol.trap(height);
	return 0;
}