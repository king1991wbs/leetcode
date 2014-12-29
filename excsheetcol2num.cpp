//Given a column title as appear in an Excel sheet, return its corresponding column number.
//
//For example:
//
//    A -> 1
//    B -> 2
//    C -> 3
//    ...
//    Z -> 26
//    AA -> 27
//    AB -> 28
//
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution{
public:
	int titleToNumber(string s){
		int result = 0;
		for(int i = s.size() - 1; i >= 0; --i){
			double base = pow(26,s.size() - i - 1);
			result += (s[i] - 'A' + 1) * base;
		}

		return result;
	}
};

int main(){
	//cout << pow(26,1) << "  " << (int)pow(26,1) << " " << (int)26 << endl;
	Solution sol;
	string str;
	cin >> str;
	cout << sol.titleToNumber(str);
	return 0;
}
