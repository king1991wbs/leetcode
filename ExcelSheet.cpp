//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
//For example:
//
//    1 -> A
//    2 -> B
//    3 -> C
//    ...
//    26 -> Z
//    27 -> AA
//    28 -> AB

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
  	string str;

        char C;
  	int mod = 0;
	int dist = 'A' - 1;

	while(n){
		if(n == 26){
			str = 'Z' + str;
			return str;
		}
		mod = n % 26;
		n = n / 26;

		if(mod == 0){
			str = 'Z' + str;
			--n
			continue;
		}
		
		C = mod + dist;
		str = C + str;
	}

	return str;
    }
};

int main(){
	int n = 28;
	Solution sol;
	while(n != 0){
		cin >> n;
		cout << sol.convertToTitle(n);
	}
}
