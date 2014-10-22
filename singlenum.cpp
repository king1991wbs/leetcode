/*
 *Given an array of integers, every element appears twice except for one. Find that single one.
 * Note:
 *Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

class Solution{
public:
	int singleNumber(int A[], int n) {
		if(n == 0) return 0;
		if(n == 1) return A[0];

		sort(A, A + n);
		int i = 0, j = 1;
		while(j < n){
			if(A[i] == A[j]){
				i = j + 1;
				j = i + 1;
			}
			else
				return A[i];
		}
		return A[i];		
	} 
};

int main(){
	int foo[] = { 10, 40, 30, 40, 30 };
	Solution sol;
	sol.singleNumber(foo, 5);
	return 0;
}
