/*************************************************************************
	> File Name: coinsInLineRecusion.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Sat 26 Apr 2014 04:24:38 PM CST
 ************************************************************************/
#include<iostream>
using namespace std;

//const int MAX_N = 100;
int main()
{
    const int N = 10;
    int A[N] = {1,2,3,4,5,6,7,8,9,10};
    //int p[MAX_N][MAX_N] = {0};

    int maxMoney(int [],int,int);
    int mm = maxMoney(A,0,N-1);
    //printf("I get %d coins",mm);
    cout << "I get " << mm << "coins" << endl;
    return 0;
}

int maxMoney(int A[],int i,int j)
{

    return max(A[i]+min((i+2 < j)?maxMoney(A,i+2,j):0,(i+1 < j-1)?maxMoney(A,i+1,j-1):0),
               A[j]+min((i+1 < j-1)?maxMoney(A,i+1,j-1):0,(i < j-2)?maxMoney(A,i,j-2):0));    
}
