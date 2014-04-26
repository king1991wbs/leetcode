/*************************************************************************
	> File Name: coinsInLine.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Sat 26 Apr 2014 03:45:41 PM CST
 ************************************************************************/

#include<iostream>
#include<cassert>
using namespace std;

const int MAX_N = 100;
int main()
{
    int maxMoney(int [],int);
    const int N = 10;
    int A[N] = {1,2,3,4,5,6,7,8,9,10};
    maxMoney(A,N);

    return 0;
}

void printMoves(int p[][MAX_N],int A[],int N)
{
    int sum1 = 0,sum2 = 0;
    int m = 0,n = N-1;
    bool myTurn = true;
    while(m <= n)
    {
        int p1 = p[m+1][n];
        int p2 = p[m][n-1];
        cout << (myTurn ? "I" : "YOU") << "take coin no.";
        if(p1 <= p2)
        {
            cout << m+1 << "(" << A[m] << ")";
            m++;
        }
        else
        {
            cout << n+1 << "(" << A[n] << ")";
            n--;
        }
        cout << (myTurn ? "," : ".\n");
        myTurn = !myTurn;
    }
    cout << "\n The total amount of money (maximum) I get is " << p[0][N-1] << ".\n";
}
int maxMoney(int A[],int N)
{
    int p[MAX_N][MAX_N] = {0};
    int a,b,c;
    for(int i = 0;i < N;i++)
        for(int m = 0,n = i;n < N;m++,n++)
    {
        assert(m < N);
        assert(n < N);
        a = ((m+2 <= N-1)             ?p[m+2][n]:0);
        b = ((m+1 <= N-1 && n-1 >= 0) ?p[m+1][n-1]:0);
        c = ((n-2 >= 0)               ?p[m][n-2]:0);
        p[m][n] = max(A[m] + min(a,b),A[n]+min(b,c));
    }
    printMoves(p,A,N);
    return p[0][N-1];
}


