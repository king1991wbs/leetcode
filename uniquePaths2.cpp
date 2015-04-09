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
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if( m <= 0 || n <= 0 )
            return 0;
        //if( m == 1 || n == 1 )
          //  return 1;

        vector<vector<int>> paths(m, vector<int>(n, -1) );
        for( int i = 0; i < m; i++ ){
            if( obstacleGrid[i][n - 1] ){
                for( int k = 0; k <= i; k++ ){
                    paths[k][n - 1] = 0;
                }
                continue;
            }
            paths[i][n - 1] = 1;
        }
        for( int j = 0; j < n; j++){
            if( obstacleGrid[m - 1][j] ){
                for( int k = 0; k < j; k++ ){
                    paths[m - 1][k] = 0;
                }
                continue;
            }
            paths[m - 1][j] = 1;
        }

        findUniquePaths(0, 0, paths, obstacleGrid);
        return paths[0][0];
    }
private:
    int findUniquePaths(int i, int j, vector<vector<int>> & paths, vector<vector<int> > &obstacleGrid){
        if( paths[i][j] != -1 )
            return paths[i][j];
        if( obstacleGrid[i][j] ){
            paths[i][j] = 0;
            return 0;
        }
        paths[i][j] = findUniquePaths(i + 1, j, paths, obstacleGrid) + findUniquePaths(i, j + 1, paths, obstacleGrid);
        return paths[i][j];
    }
};

int main(){
    vector<vector<int> > obstacleGrid(1, vector<int>(2, 0));
    obstacleGrid[0][1] = 1;
	Solution sol;
	int paths = sol.uniquePathsWithObstacles(obstacleGrid);
	cout << paths;
	return 0;
}