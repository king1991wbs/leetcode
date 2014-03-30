/*************************************************************************
	> File Name: longestpalindrome.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Fri 21 Mar 2014 01:15:55 PM CST
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

int main()
{

    string JudgePlindrome(string);
    cout << "please input a string："<< endl;
    string palindromestr;
    cin >> palindromestr;

    cout << "the longest sub palindrome string of "<< palindromestr << "is \r\n" << 
    JudgePlindrome(palindromestr);
    return 0;
}

string expandAroundCnter(string s,int l,int r)
{
    int len = s.length();
    while(l >= 0 && r <= len-1 && s[l] == s[r])
    {
        l--;
        r++;
    }

    return s.substr(l+1,r-l-1);
}

string JudgePlindrome(string palinstr)
{
    int len = palinstr.length();
    if(len == 0)
        return "";

    //use longest to denote the longest palindrome substring of a given string
    string longest = palinstr.substr(0,1);
    for(int i = 0;i < len-1;i++)
    {
        string odd = expandAroundCnter(palinstr,i,i);
        if(odd.length() > longest.length())
            longest = odd;
        string even = expandAroundCnter(palinstr,i,i+1);
        if(even.length() > longest.length())
            longest = even;
    }
    return longest;
}
