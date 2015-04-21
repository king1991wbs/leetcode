#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
    	vector<vector<int>> f(triangle.size(), vector<int>(triangle.size(),INT_MAX));
    	int minSum = INT_MAX;
    	for( int j = 0; j < triangle.size(); ++j ){
	    	int sum = pathSum(triangle.size() - 1, j, f, triangle);
	    	minSum = min(minSum, sum);
    	}
      return minSum;  
    }
    int pathSum(int i, int j, vector<vector<int> > & f, vector<vector<int> > &triangle){
    	if( i < 0 || j < 0 || j >= triangle[i].size() )
    		return INT_MAX;
    	if( f[i][j] != INT_MAX )
    		return f[i][j];
    	if( i == 0 && j == 0 )
    		return triangle[0][0];
    	int left = pathSum(i - 1, j - 1, f, triangle);
    	int right = pathSum(i - 1, j, f, triangle);
    	f[i][j] = min(left, right) + triangle[i][j];
    }
};

int main(){
	Solution sol;
	vector<vector<int>> t;
	vector<int > s(1,-10);
	t.push_back(s);
	sol.minimumTotal(t);
	return 0;
}