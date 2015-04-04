#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
    	if(s.size() <= 2)
    		return s;
    	if( nRows <= 1 )
    		return s;
        //char **c = new char *[nRows];
 
        string c[nRows];
 
        int k = 0;
        for(int j = 0; k < s.size(); j++){
        	if( j & 0x1 ){//odd
        		for( int i = nRows - 2; i > 0 ; i-- ){
        			c[i] += s[k++];
        			if(k >= s.size())
        				break;
        		}
        	}else{
        		for( int i = 0; i < nRows; i++){
        			c[i] += s[k++];
        			if(k >= s.size())
        				break;
        		}
        	}
        }

        k = 0;
        s = "";
        for(int i = 0; i < nRows; i++){
        	s += c[i];
        }
        return s;
    }
};

int main(){
	Solution sol;
	string str("PAHNAPLSIIGYIR");
	//str[0] = 'A';
	cout << str << endl;
	str = sol.convert(str, 2);
	cout << str << endl;
	return 0;
}