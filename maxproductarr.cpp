#include <iostream>

using namespace std;

class Solution {
public:
	int maxProduct(int A[], int n);
private:
	int _aux_maxproduct(int A[], int start, int end, bool negtive);
};

int Solution::maxProduct(int A[], int n){
	if (n < 2) return A[0];
	int start = 0, end = 0;
	int max = A[0];
	bool negtive = true;//复数奇数还是偶数true表示偶数
	//保证被处理数组中没有0值
	for(int i = 0; i < n; i++){
		if(A[i] > max) max = A[i];
		if(A[i] < 0) negtive = !negtive;
		if(A[i] == 0){
			if((end - start) > 1){//只有一个元素，不需调用函数
				int value = _aux_maxproduct(A, start, end - 1, negtive);
				max = value > max ? value : max;
			}
			start = i + 1;
			end   = i + 1;
			negtive = true;
			continue;
		}
		end++;
	}
	if ((end - start) > 1){//只有一个元素，不需调用函数
		int value = _aux_maxproduct(A, start, end - 1, negtive);
		max = value > max ? value : max;
	}
	return max;
}
//
int Solution::_aux_maxproduct(int A[], int start, int end, bool negtive){

	int max = 1;
	if(negtive){
		for(int i = start; i <= end; i++)
			max *= A[i];
		return max;
	}
	int value = 1;
	bool flag = true;
	for(int i = start; i <= end; i++){
		if(A[i] < 0 && flag){
			max = value > max ? value : max;
			value  = 1;
			flag = false;
			continue;
		}
		value *= A[i];
	}
	max = value > max ? value : max;

	value = 1;
	flag = true;
	for(int i = end; i >= start; i--){
		if(A[i] < 0 && flag){
			max = value > max ? value : max;
			value  = 1;
			flag = false;
			continue;
		}
		value *= A[i];
	}
	max = value > max ? value : max;
}

int main(int argc, char const *argv[])
{
	Solution sol;
	const int n = 3;
	int A[n] = { -2, 0, -1 };

	/*for(int c = 0; c < n; c++){
		A[c] = c % 2 ? 1: -1;
	}*/

	cout << sol.maxProduct(A, n);
	getchar();
	return 0;
}