/*Implement int sqrt(int x).
*
*Compute and return the square root of x.
*/
#include <iostream>
#include <cmath>

using namespace std;

class Solution{
public:
	int sqrt(int x){
		int num = -1;
		int _x = x;
		while(_x){
			num++;
			_x /= 10;
		}
		int start = pow(10, num / 2) - 1;
		int end   = pow(10, num / 2 + 1);

		while(start + 1 < end){
			int med = (start + end) / 2;
			if(med*med == x)
				return med;
			if(med >= 46341 || med*med > x)
				end = med;
			else
				start = med;
		}
		return start;
	}
};

int main(){
	//cout << sqrt(INT_MAX);
	int num;
	cin >> num;
	Solution sol;
	cout << sol.sqrt(2147395599);
	return 0;
}
