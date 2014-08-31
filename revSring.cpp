#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
	Solution();
	~Solution();

	void reverseWords(std::string &s);

private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}

void Solution::reverseWords(std::string &s)
{
	//去掉头和尾的空格
	auto iter = s.begin();
	while(*iter == ' ')
	{
		iter = s.erase(iter);
		//iter++;
	}

	iter = s.end();
	iter--;
	while(*iter == ' ')
	{
		iter = s.erase(iter);
		iter--;
	}
	//逆序操作
	std::string rs,temp;
	std::vector<std::string> v_str;
	bool flag = false;
	for(iter = s.begin(); iter != s.end(); iter++)
	{
		if(*iter == ' ' && !flag) 
		{
			v_str.push_back(temp);
			temp.clear();
			//temp = "";
			flag = true;

			continue;
		}
		if(*iter == ' ') continue;

		temp += *iter;
		flag = false;
	}
	v_str.push_back(temp);
	//合成逆序字符串
	s.clear();
	for(auto v_iter = v_str.rbegin(); v_iter != v_str.rend(); v_iter++)
	{
		s += *v_iter;
		s.append(" ");
	}
	s.erase(--s.end());//去掉多余空格
}
/*
void Solution::reverseWords(std::string &s)
{
	auto iter = s.begin();
	while(*iter == ' ')
	{
		iter = s.erase(iter);
		//iter++;
	}

	iter = s.end();
	iter--;
	while(*iter == ' ')
	{
		iter = s.erase(iter);
		iter--;
	}

	iter = s.begin();
	bool flag = false;
	std::string rs;
	while(iter != s.end())
	{
		if(*iter != ' ')
		{
			rs.insert(rs.begin(),*iter);
			flag = false;
		}
		if(*iter == ' ' && !flag)
		{
			rs.insert(rs.begin(),*iter);
			flag = true;
		}
		
		iter++;
	}
	//std::reverse(rs.begin(),rs.end());
	s = rs;
}
*/

int main()
{
	Solution ans;
	std::string s = "ifg";
	s = s + " ";
	//std::cin >> s;
	//std::cout << s;
	ans.reverseWords(s);
	
	std::cout << s;
	getchar();

	return 0;
}