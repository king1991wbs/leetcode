/*************************************************************************
	> File Name: lengthOfLongestSubString.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Sat 12 Apr 2014 01:30:16 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    int lengthOfLongestSubString(string);
    cout << "please input a string:" << endl;
    string str;
    cin >> str;
    int length = lengthOfLongestSubString(str);
    cout << "the longest substring length without repeat is:" << length << endl;;
    return 0;
}

int lengthOfLongestSubString(string str)
{
    //use 0~25 to stand for 'a-z' seperatly
    bool existFlag[26] = {false};
    int start = 0;
    int end = 0;
    int maxLength = 0;
    while(end != str.length() - 1)
    {
        if(existFlag[str[end] - 'a'])
        {
            maxLength = end - start;
            while(str[start] != str[end])
            {
                existFlag[str[start] - 'a'] = false;
                start++;
            }
            start++;
            //end++;
        }
        else
        {
            existFlag[str[end] - 'a'] = true;
            //end++;
        }
        end++;
    }
    return maxLength;
}
