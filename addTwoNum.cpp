/*You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include <iostream>

using namespace std;


 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p_l1 = l1;
        ListNode *p_l1Pre = l1;

        int increment = 0;
        while(l1 && l2){
        	int temp = l1->val + l2->val + increment;
        	if(temp >= 10){
        		temp -= 10;
        		increment = 1;
        	}else{
        		increment = 0;
        	}

        	l1->val = temp;

        	p_l1Pre = l1;
        	l1 = l1->next;
        	l2 = l2->next;
        }
        if( NULL == l1 && NULL == l2 ){
        	if(increment)
        		p_l1Pre->next = new ListNode(increment);
        	return p_l1;
        }

        while(l1 && increment){
        	int temp = l1->val + increment;
        	if(temp >= 10){
        		temp -= 10;
        		increment = 1;
        	}else{
        		increment = 0;
        	}
        	l1->val = temp;
        	p_l1Pre = l1;
        	l1 = l1->next;
        }
        if(NULL == l2){
        	if(increment)
        		p_l1Pre->next = new ListNode(increment);
        	return p_l1;
        }
        p_l1Pre->next = l2;
        while(l2 && increment){
        	int temp = l2->val + increment;
        	if(temp >= 10){
        		temp -= 10;
        		increment = 1;
        	}else{
        		increment = 0;
        	}
        	l2->val = temp;
        	p_l1Pre = l2;
        	l2 = l2->next;
        }
        if(increment){
        	p_l1Pre->next = new ListNode(increment);
        }
        return p_l1;
    }
};