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
    ListNode* sortList(ListNode* head) {
        if(NULL == head || NULL == head->next)
        	return head;

        ListNode *fast = head, *slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
        	fast = fast->next->next;
        	slow = slow->next;
        }

        //break
        fast = slow;
        slow = slow->next;
        fast->next = NULL;

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        return mergeSort(l1, l2);
    }

    ListNode* mergeSort(ListNode *l1, ListNode *l2){
    	ListNode dummy(-1);
    	ListNode *p = &dummy;

    	while(l1 != NULL && l2 != NULL){
    		if(l1->val < l2->val){
    			p->next = l1;
    			p = l1;
    			l1 = l1->next;
    		}else{
    			p->next = l2;
    			p = l2;
    			l2 = l2->next;
    		}
    	}

    	if(l1 == NULL){
    		p->next = l2;
    	}
    	if(l2 == NULL){
    		p->next = l1;
    	}

    	return dummy.next;
    }
};

int main(){
	int val;
	ListNode *head = new ListNode(3);
	ListNode *_h = head;
	while(cin >> val){
		head->next = new ListNode(val);
		head = head->next;
		if(val == 0)
			break;
	}
	Solution sol;
	_h = sol.sortList(_h);

	while(_h){
		cout << _h->val << endl;
		_h = _h->next;
	}
	return 0;
}