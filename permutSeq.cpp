#include <iostream>
#include <functional>
#include <numeric>
#include <vector>
#include <string>

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
			str += seq[m] + 48;
			seq.erase(seq.begin() + m);
			k = k - m * iFrac;
		}
		//string temp(seq[0]);
		str += seq[0] + 48;//最后一个(加上48进行acsii转意)

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
	/*string str;
	int t = 1 + 48;
	str += t;*/
	Solution sol;
	sol.getPermutation(2, 1);
	//sol.getPermutation(9, 54494);
}
