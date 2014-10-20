#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution{
public:
	string countAndSay(int n){
		string s = "1";
		string result = s;

		while(--n){
			//int i = 0;
			int count = 0;
			char tchar = s[0];
			string str;

			for(int i = 0; i < s.length(); i++){
				if(s[i] == tchar)
					count++;
				else{
					stringstream ss;
					ss << count;
					/*string tem;
					ss >> tem;*/
					str += ss.str();
					ss.str("");
					
					ss << tchar;
					str += ss.str();
					ss.str("");

					tchar = s[i];
					count = 1;
				}
			}
			stringstream ss;
			ss << count;
			str += ss.str();
			ss.str("");

			ss << tchar;
			str += ss.str();
			ss.str("");

			s = str;
		}
		return s;
	}
};

int main()
{
	/*stringstream ss;
	ss << "kk";
	cout << ss.str();*/
	Solution sol;
	cout << sol.countAndSay(1);
	return 0;
}
