#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
		int len_s = s.length();
		vector<bool> partiable(len_s + 1, false);
		partiable[0] = true;
		
		vector<vector<int> > cut(len_s + 1, vector<int>());
		for (int j = 1; j <= len_s; j++){
			for (int i = j - 1; i >= 0; i--){
				//partiable[j] = partiable[i] && (dict.find(s.substr(i, j - i + 1)) != dict.end());
				if (partiable[i] && (dict.find(s.substr(i, j - i)) != dict.end())){
					partiable[j] = true;
					cut[j].push_back(i);//可拆分下标
				}
			}
		}
		vector<string> result;
		vector<string> path;
		getsentence(s, len_s, cut, path, result);

		return result;
    }
private:
	void getsentence(string s, int n,vector<vector<int> > cut, vector<string> &path, vector<string> &result){
		if(n == 0){
			string temp("");
			for(auto iter = path.rbegin(); iter != path.rend(); ++iter){
				temp = temp + *iter + " ";
			}
			temp.erase(temp.end() - 1);
			result.push_back(temp);
		}
		for(auto iter = cut[n].begin(); iter != cut[n].end(); ++iter){
			path.push_back(s.substr(*iter, n - *iter));
			getsentence(s, *iter, cut, path, result);
			path.pop_back();
		}
	}
};


int main(){
	string s = "dogs";
	unordered_set<string> dict;
	dict.insert("dog");
	dict.insert("s");
	dict.insert("dogs");
	dict.insert("gs");
	Solution sol;
	sol.wordBreak(s, dict);
	return 0;
}