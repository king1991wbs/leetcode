#include <iostream>

using namespace std;

class Solution {
public:
	int maxProduct(int A[], int n);
};

int Solution::maxProduct(int A[], int n){

	int max = A[0];
	for (int i = 0; i < n; i++){
		if (A[i] > max)	max = A[i];
	}

	int value = 1;
	for (int i = 0; i < n - 1; i++){
		value = A[i];
		for (int j = i + 1; j < n; j++){
			value = value * A[j];
			if (value > max) max = value;
		}
	}

	return max;
}

int main(int argc, char const *argv[])
{
	Solution sol;
	const int n = 300000;
	int A[n];// {1,-2,3,4,5,6};

	for(int c = 0; c < n; c++){
		A[c] = c % 2 ? 1: -1;
	}

	cout << sol.maxProduct(A, n);

	return 0;
}