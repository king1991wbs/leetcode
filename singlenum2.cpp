/*Given an array of integers, every element appears three times except for one. Find that single one.
*
*Note:
*Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <iostream>

using namespace std;

class Solution{
public:
	int singleNumber(int A[], int n) {
		if(n == 0) return 0;
		if(n <= 3) return A[0];

        	sort(A, A + n);
		int i = 0, j = 1, k = 2;
		while(k < n){
			if(A[i] == A[j] && A[i] == A[k]){
				i += 3;
				j += 3;
				k += 3;
			}
			else
				return A[i];	
		}
		return A[i];		
	} 
};
