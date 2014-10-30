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
        
        if(!s.length())
            return result;

        for(int i = 0; i < s.length(); ++i){
            findPalindrome(0, i, s, part, result);
        }
        return result;
    }
private:
    void findPalindrome(int i, int j, const string &s, vector<string> part, vector<vector<string>> &result);
    inline bool isPalindrome(int i, int j, const string &s);
};

void Solution::findPalindrome(int i, int j, const string &s, vector<string> part, vector<vector<string>> &result){
    if(isPalindrome(i, j, s)){
        part.push_back(s.substr(i, j - i + 1));
        if(j == s.length() - 1){
            result.push_back(part);
            return;
        }
        for(int m = j + 1; m < s.length(); ++m){
            findPalindrome(j + 1, m, s, part, result);
        }
    }
}

inline
bool Solution::isPalindrome(int i, int j,const string &s){
    while(i <= j && s[i] == s[j]){
        ++i;
        --j;
    }
    return i > j;
}
int main(){
    string s = "aaasaaabaaaa";
    Solution sol;
    sol.partition(s);
    return 0;
}
