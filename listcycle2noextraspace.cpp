#include <iostream>

using namespace std;


/**
  Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
    	std::unordered_set<ListNode*> nodes;
    	while(head){
    		if(head->val == INT_MAX)
                break;
            head->val = INT_MAX;
            head = head->next;
    	}
    	return head;
    }
};