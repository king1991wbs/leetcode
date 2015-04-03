#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
		set<string> subStrCount;
		for( int i = 0; ( i + 9 ) < s.length(); i++ ){
			string temp = s.substr(i, 10);
			if( subStrCount.find(temp) != subStrCount.end() )
				continue;
			bool flag = isMoreThanOnce(s, i+1, temp);
			if(flag)
				subStrCount.insert(temp);
		}
		vector<string> result(subStrCount.begin(), subStrCount.end());
		
		return result;
    }
private:
	//next array
	void getNext(int *next, const string & str){
		next[0] = -1;
		int k = -1;
		int j = 0;
		while( j < str.length() - 1){
			if(k == -1 || str[k] == str[j]){
				++k;
				++j;
				next[j] = k;
			}else{
				k = next[k];
			}
		}
	}

	bool isMoreThanOnce(const string & s, int pos, const string & str){
		int next[10];
		getNext(next, str);
		int i = pos;
		int j = 0;
		while( i < s.length() && j < str.length() ){
			if(s[i] == str[j]){
				++i;
				++j;
			}else{
				j = next[j];
				if(j == -1){
					++i;
					++j;
				}
			}
		}
		if( j == str.length() )
			return true;
		return false;
	}
};

int main(){
	string s = "AAAAAAAAAAAA";
	Solution sol;
	vector<string> rst = sol.findRepeatedDnaSequences(s);
	for( auto iter = rst.begin(); iter != rst.end(); ++iter )
		cout << *iter << endl;
	return 0;
}