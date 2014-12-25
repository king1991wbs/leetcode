//Given an array of size n, find the majority element. The majority element is the element that appears more than n/2 times.
//
//You may assume that the array is non-empty and the majority element always exist in the array.
//
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int count = 1,element = 0;
        element = num[0];

        auto iter = num.begin();
        for(++iter;iter != num.end(); ++iter){
        	if(element == *iter){
        		++count;
        	}
        	else if(count == 0){
        		count = 1;
        		element = *iter;
        	}
        	else{
        		--count;
        	}
        }

        return element;
    }
};

int main(){
	vector<int> num = {6,5,5};
	Solution sol;
	cout << sol.majorityElement(num);
}