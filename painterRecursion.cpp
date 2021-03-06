/*************************************************************************
	> File Name: painterRecursion.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Mon 21 Apr 2014 02:18:01 PM CST
 ************************************************************************/

#include<iostream>
#include<climits>
using namespace std;

const int  MAX_N = 100;
int findMax(int [],int,int);
int main()
{
    int A[] = {100,200,300,400,500,600,700,800,900};
    int numA = 9;
    int k = 3;

    int minCost = findMax(A,numA,k);
    cout << "the minist cost is:" << minCost;
    return 0;
}

int findMax(int A[],int n,int k)
{
    int M[MAX_N+1][MAX_N+1] = {0};
    int cum[MAX_N+1] = {0};
    
    //记录前i项的和
    for(int i = 1;i <= n;i++)
    {
        cum[i] = cum[i-1] + A[i-1];
    }

    for(int i = 1;i <= n;i++)
    {
        M[i][1] = cum[i];
    }
    for(int i = 1;i <= k;i++)
    {
        M[1][i] = A[0];
    }

    for(int i = 2;i <= k;i++)
    {
        for(int j = 2;j <= n;j++)
        {
            int best = INT_MAX;
            for(int p = 1;p <= j;p++)
            {
                best = min(best,max(M[p][i-1],cum[j]-cum[p]));
            }
            M[j][i] = best;
        }
    }
    return M[n][k];
}
