/*************************************************************************
	> File Name: palindrome.cpp
	> Author: wilson
	> Mail: wilson_91@foxmial.com 
	> Created Time: Wed 19 Mar 2014 03:59:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    int reverseintegernumber(int);
    cout << "please input a number for judge:"<< endl;
    int palindromenumber = 0;
    cin >> palindromenumber;
    int reversedpanumber = 0;
    reversedpanumber = reverseintegernumber(palindromenumber);
    if(reversedpanumber == palindromenumber)
        cout << palindromenumber <<"is a palindromenumber!"<< endl;
    else
        cout <<"sorry,this is not a palindrome number!"<< endl;
    return 0;
}

int reverseintegernumber(int fortest)
{
    int front = fortest;
    int back = 0;
    while(front != 0)
    {
        back = back*10 + front % 10;
        front /= 10;
    }

    return back;
}
