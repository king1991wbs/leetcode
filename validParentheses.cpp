/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */


#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> cstack;
		char ch;
		for( auto iter : s ){
			switch(iter){
				case '(':
				case '{':
				case '[':
					cstack.push(iter);
					break;
				case ')':
					if( cstack.empty() )
						return false;
					ch = cstack.top();
					cstack.pop();
					if( ch != '(' )
						return false;
					break;
				case ']':
					if( cstack.empty() )
						return false;
					ch = cstack.top();
					cstack.pop();
					if( ch != '[' )
						return false;
					break;
				case '}':
					if( cstack.empty() )
						return false;
					ch = cstack.top();
					cstack.pop();
					if( ch != '{' )
						return false;
					break;
				default:
					return false;
			}
		}
		if( cstack.empty() )
			return true;
		return false;
    }
};

int main(int argc, char const *argv[])
{
	Solution sol;
	string s = "[";
	cout << sol.isValid(s);
	return 0;
}