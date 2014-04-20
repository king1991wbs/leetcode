/*************************************************************************
	> File Name: painterPartitionLowestCost.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Sun 20 Apr 2014 01:25:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int partition(int [],int,int);
int main()
{
    int boards[] = {100,200,300,400,500,600,700,800,900};
    int requirePainters = 3;
    int numArr = 9;
    int lowestcost = partition(boards,numArr,requirePainters);
    cout << "the lowest cost is:" << lowestcost << endl;
    return 0;
}

int maxOfBoards(int boards[],int numArr)
{
    //int size = sizeof(boards);
    //
    int max = boards[0];
    for(int i = 1;i < numArr;i++)
    {
        if(max < boards[i])
            max = boards[i];
    }
    return max;
}

int sumOfBoards(int boards[],int numArr)
{
    //int size = sizeof(boards);

    int sum = 0;
    for(int i = 0;i < numArr;i++)
    {
        sum += boards[i];
    }
    return sum;
}

int numOfPainters(int boards[],int numArr,int maxLengthPerPainter)
{
    //int size = sizeof(boards)/sizeof(int);
    int total = 0;
    int numPainters = 1;//0;it's more meaningful to initialise numPainter be 1 than 0
    for(int i = 0;i < numArr;i++)
    {
        total += boards[i];
        if(total > maxLengthPerPainter)
        {
            total = boards[i];
            numPainters++;
        }
       // else
       // {
       //     total += boards[i];
       // }
    }

    //return numPainters + 1;
    return numPainters;
}
int partition(int boards[],int numArr,int requirePainters)
{
    int lo = maxOfBoards(boards,numArr);
    int hi = sumOfBoards(boards,numArr);

    //int numPainters = 1;
    while(lo < hi)
    {
        int mid = (lo + hi)/2;
        int numPainters = numOfPainters(boards,numArr,mid);
        if(numPainters > requirePainters)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    return lo;
}
