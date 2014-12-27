//Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//
//If the fractional part is repeating, enclose the repeating part in parentheses.
//
//For example,
//
//Given numerator = 1, denominator = 2, return "0.5".
//Given numerator = 2, denominator = 1, return "2".
//Given numerator = 2, denominator = 3, return "0.(6)".

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
	string result, fracStr;
	//stringstream ss;

	bool sign = false;//同号不同号
	if(numerator >= 0 && denominator > 0 || numerator <= 0 && denominator < 0)
		sign = true;

	long long int numer = numerator, denomi = denominator;
	numer = abs(numer); denomi = abs(denomi);
	long long int intPart = numer / denomi;
	//result += intPart;
	//result += ".";

	int insertPos = -1;//
	long long int remainPart = numer - intPart * denomi;
	unordered_map<int, int> remainHash;
	remainHash[remainPart] = 0;
	while(remainPart){
		//ss << (remainPart * 10) / denomi;
		fracStr += to_string(remainPart * 10 / denomi);
		remainPart = (remainPart * 10) % denomi;
		
		if(remainHash.find(remainPart) != remainHash.end())
		{
			//auto iter = remainHash.find(remainPart);
			//++iter;
			////GDB hash 的insert和vs的插入顺序是相反的·
			//insertPos = distance(iter, remainHash.end());
			//--insertPos;
			//cout << insertPos << *--remainHash.end() << *iter << endl;
			insertPos = remainHash[remainPart];
			break;
		}
		remainHash[remainPart] = fracStr.size();
	}
	
	//fracStr = ss.str();
	//ss.clear();
	//ss.str("");
	if(insertPos != -1){
		//insertPos++;
		fracStr.insert(insertPos, "(");
		fracStr.append(")");	
	}
		
	//ss << intPart;
	//result += ss.str();
	result += to_string(intPart);
	if(!fracStr.empty()){
		result.append(".");
		result.append(fracStr);
	}

	if(!sign) result.insert(0, "-");
	return result;
    }
};

int main(){
	Solution sol;
	cout << sol.fractionToDecimal(0,-5);
	return 0;
}
