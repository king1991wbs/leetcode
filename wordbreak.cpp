#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
		int len_s = s.length();
		vector<bool> partiable(len_s + 1, false);
		partiable[0] = true;
		
		for (int j = 1; j <= len_s; j++){
			for (int i = j - 1; i >= 0; i--){
				//partiable[j] = partiable[i] && (dict.find(s.substr(i, j - i + 1)) != dict.end());
				if (partiable[i] && (dict.find(s.substr(i, j - i)) != dict.end())){
					partiable[j] = true;
					break;
				}
			}
		}
		return partiable[len_s];
    }
};


int main(){
	string s = "dogs";
	unordered_set<string> dict;
	dict.insert("dog");
	dict.insert("gs");
	Solution sol;
	sol.wordBreak(s, dict);
	return 0;
}