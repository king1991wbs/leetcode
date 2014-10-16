#include <iostream>
#include <unordered_set>

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
        auto pos = nodes.find(head);
        if(pos != nodes.end())
          break;
        nodes.insert(head);
        head = head->next;
      }
      return head;
    }
};
int main(){

	return 0;
}