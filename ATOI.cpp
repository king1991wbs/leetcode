#include <iostream>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
		while(*str == ' ') ++str;//ȥ���ַ�ǰ��Ŀո�
		
		bool positive =true;//�������߸����ж�
		if(*str == '+' || *str == '-')
		{
			positive = *str == '+' ? true : false;
			
			++str;
			//positive = false;
		}
		//ȥ���˶���Ŀո�������ź�
		if(*str < '0' || *str > '9')
			return 0;

		while(*str == '0') ++str;//ȥ��ǰ׺0

		int count = 0;//ͳ������λ��
        while(*str != '\0')
		{
			if(!(*str >= '0' && *str <= '9'))	break;
			str++;
			count++;
		}

		if(count == 0)
		{
			cout << "please give an integer!" << endl;
			getchar();
			return 0;
		}

		long long value = 0;
		str -= count;
		if(positive)
		{
			while(count--)
			{
				value = value * 10 + *str++ - '0';
				if(value > INT_MAX)	return INT_MAX;
			}
		}else
		{
			while(count--)
			{
				value = value * 10 - *str++ + '0';
				if(value < INT_MIN)	return INT_MIN;
			}
		}
		

		cout << " : " << value << endl;
		getchar();
		return value;
    }
};

int main()
{
	const char *str = "    10522545459";
	Solution sol;
	int value = sol.atoi(str);
	return 0;
}