/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
    	if( m <= 0 || n <= 0 )
    		return 0;
    	if( m == 1 || n == 1 )
    		return 1;

        vector<vector<int>> paths(m, vector<int>(n, 0) );
        for( int i = 0; i < m; i++ )
        	paths[i][n - 1] = 1;
        for( int j = 0; j < n; j++)
        	paths[m - 1][j] = 1;

        findUniquePaths(0, 0, paths);
        return paths[0][0];
    }
private:
	int findUniquePaths(int i, int j, vector<vector<int>> & paths){
		if( paths[i][j] != 0 )
			return paths[i][j];

		paths[i][j] = findUniquePaths(i + 1, j, paths) + findUniquePaths(i, j + 1, paths);
		return paths[i][j];
	}
};

int main(){
	Solution sol;
	int paths = sol.uniquePaths(0, 12);
	cout << paths;
	return 0;
}