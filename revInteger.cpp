#include <iostream>
#include <cstdlib>

using namespace std;

class Solution{
public:
	int reverse(int x){
		bool negtive = false;
		negtive = x < 0 ? true : false;

		x = abs(x);
		int result = 0;
		while(x){
			int tem = x % 10;
			x /= 10;
			result = result * 10 + tem;
		}

		return negtive ? -result : result;
	}
};

int main(){
	int var = 987654321;

	Solution sol;
	cout << sol.reverse(var);
	return 0;
}
