#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> operand;
		int operL,operR;
		//string str;

		for(auto iter : tokens)
		{
			if(!(iter.size() == 1 && (iter[0] < '0' || iter[0] > '9')))
			{
				int temp = stoi(iter);
				operand.push_back(temp);
				continue;
			}
			switch (iter[0])
			{
			case '+':
				makeRL(operL,operR,operand);
				operand.push_back(operL + operR);
				break;
			case '-':
				makeRL(operL,operR,operand);
				operand.push_back(operL - operR);
				break;
			case '*':
				makeRL(operL,operR,operand);
				operand.push_back(operL * operR);
				break;
			case '/':
				makeRL(operL,operR,operand);
				operand.push_back(operL / operR);
				break;
			default:
				//operand.push_back(iter[0] - '0');
				break;
			}
		}
		return operand[0];
    }
private:
	void makeRL(int &operL,int &operR,vector<int> &operand)
	{
		operR = *(operand.end() - 1);
		operand.pop_back();
		operL = *(operand.end() - 1);
		operand.pop_back();
	}
};

int main()
{
	Solution sol;

	vector<string> tokens;
	tokens.push_back("3");
	tokens.push_back("-4");
	tokens.push_back("+");

	sol.evalRPN(tokens);
}