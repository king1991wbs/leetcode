#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<int,int> subStrCount;
		hash<string> strID;
		vector<string> result;

		for( int i = 0; ( i + 9 ) < s.length(); i++ ){
			string temp = s.substr(i, 10);
			int id = strID(temp);
			//cout << temp << endl;
			if( subStrCount.find( id ) != subStrCount.end() ){
				//cout << temp << endl;
				if(subStrCount[id] == 0)
					result.push_back(temp);
				subStrCount[id]++;//将所有10长度字串保存并统计个数
			}else{
				subStrCount[id] = 0;//first time 
			}
		}

		return result;
    }
};

int main(){
	return 0;
}