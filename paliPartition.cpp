/*Given a string s, partition s such that every substring of the partition is a palindrome.
*
*Return all possible palindrome partitioning of s.
*
*For example, given s = "aab",
*    Return
*
*      [
*          ["aa","b"],
*          ["a","a","b"]
*      ]
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public :
    vector<vector<string>> partition(string s){
        vector<string> part;
        vector<vector<string>> result;

	vector<vector<bool>> palindRecord(s.size(), vector<bool>(s.size(), false));
	for(int i = 0; i < s.size(); ++i){
		for(int j = i; j < s.size(); ++j)
			palindRecord[i][j] = isPalindrome(i, j, s);
	}

        if(!s.length())
            return result;

        for(int i = 0; i < s.length(); ++i){
			findPalindrome(0, i, s, part, result, palindRecord);
        }
        return result;
    }
private:
    void findPalindrome(int i, int j, const string &s, vector<string> &part, vector<vector<string>> &result, vector<vector<bool>> &palindRecord);
    bool isPalindrome(int i, int j, const string &s);
};

void Solution::findPalindrome(int i, int j, const string &s, vector<string> &part, vector<vector<string>> &result, vector<vector<bool>> &palindRecord){
	if(palindRecord[i][j]){
     	   	part.push_back(s.substr(i, j - i + 1));
        	if(j == s.length() - 1){
       	   	     	result.push_back(part);
			part.pop_back();
            	return;
        }
        for(int m = j + 1; m < s.length(); ++m){
			findPalindrome(j + 1, m, s, part, result, palindRecord);
        }
		part.pop_back();
    }
}

bool Solution::isPalindrome(int i, int j,const string &s){
    //int _i = i, _j = j;
	while(i <= j && s[i] == s[j]){
        ++i;
        --j;
    }
	//palindRecord[_i][_j] = i > j ? true : false;
    return i > j;
}
int main(){
    string s = "fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi";
	//string s = "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababab";
    Solution sol;
    sol.partition(s);
    return 0;
}
