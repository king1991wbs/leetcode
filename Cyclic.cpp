/*************************************************************************
 *
	> File Name: Cyclic.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Sun 30 Mar 2014 10:19:15 AM CST
 ************************************************************************/
#include<iostream>
#include "Cyclic.h"
using namespace std;
cyclic::cyclic()
{
 cyc_start = NULL; 
}
cyclic::~cyclic()
{}
pNode cyclic::getStart()
{
    return this->cyc_start;
}

void cyclic::insert(int con2insert)
{
    pNode ins = new Node;
//    int *a = new int;

    ins->content = con2insert;
    ins->next = NULL;
    
    if(this->cyc_start == NULL)
    {
        this->cyc_start = ins;
        ins->next = ins;
        return;
    }   

    pNode front,back;
    front = this->cyc_start;
    back = front->next;

    //front = back 
    //只有一个节点/
    //mZ
   while(true) 
    {
        //the connected place of front and end
        if(front->content > back->content && (con2insert >= max(front->content,back->content) 
                                              || con2insert <= min(front->content,back->content)))
        {
            ins->next = back;
            front->next = ins;
            return;
        }

        if(back == this->cyc_start)
        {
            //插入判断
            if(con2insert > back->content)
            {
                front = back;
                back = back->next;
            }
            ins->next = back;
            front->next = ins;
            return;
        }
        
        if(con2insert >= front->content && con2insert <= back->content)
        {
            ins->next = back;
            front->next = ins;
            return;
        }

        //其他情况
        //
        //

        front = back;
        back = back->next;
    }
}

int main()
{
    int con2insert;
    con2insert = 0;

    cyclic cycle;
    //cycle.insert(con2insert);

    cout<<"please input content:"<<endl;
    cin >> con2insert;
    while(con2insert >= 0)
    {
        cycle.insert(con2insert);
        cout <<"please input content:"<<endl;
        cin >> con2insert;   
    }

    pNode start = cycle.getStart();
    while(start->next != cycle.getStart())
    {
        cout<<start->content<<" ";
        start = start->next;
    }
    cout<<start->content<<endl;

    return 0;
}
