//Implement pow(x, n).

#include <iostream>
#include <cmath>

using namespace std;

class Solution{
	public:
		double pow(double x, int n){
			//cout << x << n << endl;
			if (n == 0)
				return 1;
			if (x == 1 || x == -1)
				return abs(n) % 2 ? x : abs(x);

			double tem = 1.0;

			if(n < 0){
				if(x == 0)
					return INFINITY;
				n = -n;
				while(n--){
					tem *= x;
					if (tem == INFINITY || tem == 0)
						return tem;
				}
				return 1 / tem;
			}

			while(n--){
				tem *= x;
				if (tem == INFINITY || tem == 0)
					return tem;
			}
			return tem;
		}
};

int main(){
	cout << pow(8.88023, 3) << endl;
	Solution sol;
	//cout << INFINITY;
	cout << sol.pow(8.88023, 3);
	return 0;
}
