#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
	int maxProduct(int A[], int n);
};

int Solution::maxProduct(int A[], int n){
	//constexpr int _n = n;
	//int **R = new int*[n];
  int **R = (int **)malloc(sizeof(int*) * n);
  for(int row = 0; row < n; row++){
    //R[row] = new int[n];
    R[row] = (int *)malloc(sizeof(int) * n);
  }

	int max = A[0];
	for (int i = 0; i < n; i++){
		R[i][i] = A[i];
		if (A[i] > max)	max = A[i];
	}

	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			R[i][j] = R[i][j - 1] * A[j];
			if (R[i][j] > max) max = R[i][j];
		}
	}
  /*
  for(int row = 0; row < n; row++)
    delete [] R[row];
  delete [] R;
  */
  for(int row = 0; row < n; row++)
     free(R[row]);
  free(R);

	return max;
}

int main(int argc, char const *argv[])
{
	Solution sol;
	const int n = 30000;
	int A[n];// {1,-2,3,4,5,6};

	for(int c = 0; c < n; c++){
		A[c] = c % 2 ? 1: -1;
	}

	cout << sol.maxProduct(A, n);

	return 0;
}