/*************************************************************************
	> File Name: Cyclic.h
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Sun 30 Mar 2014 10:03:47 AM CST
 ************************************************************************/

#include<iostream>

typedef struct node
{
    int content;
    node *next;
}Node,*pNode;

class cyclic
{
    private:
    pNode cyc_start;//point to the start position of the cycle list
    public:
    cyclic();
    ~cyclic();
    pNode getStart();
    void insert(int con2insert);//insert a new node into the cycle list
};
