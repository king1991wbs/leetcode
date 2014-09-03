#include <iostream>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
		
		vector<int> seq;
		for(int init = 1; init <= n; init++)
			seq.push_back(init);

		string str;
        for (int i = n-1; i >=1; i--)
		{
			int iFrac = frac(i);
			int m = (k - 1) / iFrac;
			str += seq[m];
			seq.erase(seq.begin() + m);
			k = k - m * iFrac;
		}
		str += seq[0];//最后一个

		return str;
     }
private:
	inline int frac(int i){
		int f = 1;
		for(int _i = i; _i >= 1; _i--)
			f *= _i;
		return f;
	}
};


int main()
{
	Solution sol;
	sol.getPermutation(1, 1);
	//sol.getPermutation(9, 54494);
}
