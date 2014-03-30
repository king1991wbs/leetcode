/*************************************************************************
	> File Name: linearpalindrome.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Sat 22 Mar 2014 03:34:39 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

string preProcess(string s)
{
    int strlen = s.length();
    if(strlen == 0) return "^$";
    string ret = "^";
    for(int i = 0;i < strlen ;i++)
        ret += "#" + s.substr(i,1);//s[i];

    ret += "#$";
    return ret;
}
string longestPalindrome(string s)
{
    string T = preProcess(s);
    int strlen = T.length();
    int *p = new int[strlen];
    int center,right;
    center = 0;
    right = 0;
    for(int i = 0;i < strlen - 1;i++)
    {
        int i_mirror = 2*center - i;
        //assign a initial value;
        p[i] = (right > i)? min(right - i,p[i_mirror]) : 0;

        while(T[i + 1 + p[i]] == T[i - 1 - p[i]])
            p[i]++;

        if(i + p[i] > right)
            {
                center = i;
                right = i + p[i];
            }

    }

    int maxLen = 0;
    int centerIndex = 0;
    for(int i = 1;i < strlen - 1;i++)
    {
        if(p[i] > maxLen)
        {
            maxLen = p[i];
            centerIndex = i;
        }
    }

    delete [] p;

    return s.substr((centerIndex - 1 - maxLen)/2,maxLen);
}

int main()
{
    cout << "please input a string:" << endl;
    string cadipali;
    cin >> cadipali;
    
    cout << "the longest substring is:" << endl
    << longestPalindrome(cadipali);
    return 0;
}
