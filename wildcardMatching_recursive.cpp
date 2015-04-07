/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
 */
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int i = 0, j = 0;
        if( NULL == s || NULL == p )
        	return false;

        return match(s, i, p, j);
    }
private:
	bool match(const char * s, int i, const char * p, int j);
};

bool Solution::match(const char * s, int i, const char * p, int j){
	while( s[i] != '\0' && p[j] != '\0' ){
		if( p[j] == '?' ){
			i++;
			j++;
			continue;
		}
		if( p[j] == '*' ){
			if( p[j + 1] == '\0' )
				return true;
			if( p[j + 1] == '*' ){
				j++;
				continue;
			}
			while( s[i] != '\0' ){
				bool rst = match(s, i, p, j + 1);
				if(rst)
					return true;
				i++;
			}
			return false;
		}
		if( s[i] == p[j] ){
			i++;
			j++;
			continue;
		}
		return false;
	}
	if( s[i] == '\0' && p[j] == '\0' )
		return true;//match
	return false;//partial match
}

int main(){
	Solution sol;
	cout << sol.isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", 
		"ab*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb");
	return 0;
}