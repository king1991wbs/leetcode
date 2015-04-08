/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
 */
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
    	while( !s.empty() && s[s.size() - 1] == ' ' )
        	s.erase( s.size() - 1 );
        while( !s.empty() && s[0] == ' ' )
        	s.erase(0, 1);
        if( !s.empty() && (s[0] == '-' || s[0] == '+') )
    		s.erase(0,1);
    	if( s.size() == 0 )
    		return false;


        string str1,str2;//split by 'e'
        size_t epos = s.find('e');
        str1 = s.substr( 0, epos );	cout << str1 << endl;
        if( str1.empty() )
        	return false;

        if( epos != string::npos )
        	str2 = s.substr( epos + 1 );
        else
        	str2 = "";
        cout << str2 << endl;
        
        if( epos != string::npos && ( str1.empty() || str2.empty() ) )
        	return false;
        
        size_t i = 0;
		if( str2.size() && ( str2[i] == '-' || str2[i] == '+' ) )
			i++;
        bool valid = true;
        if( epos != string::npos )//允许str2为空
        	valid = isPureNum(str2, i);
        if( !valid )
        	return false;
        size_t ppos = str1.find('.');
        string str11 = str1.substr( 0, ppos );		
        cout << str11 << endl;
        string str22;
        if( ppos != string::npos )
        	str22 = str1.substr( ppos + 1 );		
        else
        	str22 = "";
        cout << str22 << endl;
        if( ppos != string::npos && str11.empty() && str22.empty() )
        	return false;

        if( !str22.empty() && !str11.empty() ){
        	return isPureNum(str11,0) && isPureNum(str22,0);
        }
        if( !str22.empty() )//如果是非空则必须满足纯数字。否则不一定
        	return isPureNum(str22, 0);
		return isPureNum(str11, 0);
    }
private:
	bool isPureNum( const string & str, size_t i ){
		if( str.empty() || i == str.size() )
			return false;

		for( ; i < str.size() && str[i] >= '0' && str[i] <= '9' ; i++ )
			;
		return i == str.size();
	}
};

int main(){
	string s = " 005047e+6";
	Solution sol;
	cout << sol.isNumber(s);
	return 0;
}