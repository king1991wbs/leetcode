/*************************************************************************
	> File Name: testpalindromestr.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Thu 20 Mar 2014 10:07:19 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    bool testpalin(string);
    cout <<"please input a string for test:"<<endl;
    string str;
    cin >> str;
    
//    bool isPalindrome;
//    isPalindrome = testpalin(str);
    if(testpalin(str))
        cout << str << "is palindrome!";
    else
        cout << str << "is not a palindrome!";

    return 0;
}

bool testpalin(string str)
{
    int strlen;
    strlen = str.length();
    
    if(strlen == 0)
        return false;
    if(strlen == 1)
        return true;
    if(strlen == 2)
        return str[0]==str[1];

    return (str[0] == str[strlen-1]) && testpalin(str.substr(1,strlen-2));
}
