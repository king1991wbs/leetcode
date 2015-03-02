//Rotate an array of n elements to the right by k steps.

//For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
//
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        for(int i = 0; i < k; ++i){
		int temp = nums[n-1];
		for(int j = n-1; j > 0; --j){
			nums[j] = nums[j-1];
		}
		nums[0] = temp;
	}
    }
};

int main(){
	int nums[7] = {1,2,3,4,5,6,7};
	Solution sol;
	sol.rotate(nums, 7, 3);
}
