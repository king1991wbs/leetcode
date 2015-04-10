/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
    	if( n <= 1 ){
    		return n;
    	}
  		vector<int> rst(n+1, 0);
  		rst[0] = 1;
  		rst[1] = 1;
  		for( int k = 2; k <= n; k++ ){
  			for(int i = 1; i <= k; i++ ){
  				rst[k] += rst[i - 1]*rst[k-i];
  			}
  		}
  		return rst[n];
    }
};

int main(){
	Solution sol;
	cout << sol.numTrees(100);
	return 0;
}