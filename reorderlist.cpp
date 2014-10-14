#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head);
};

void Solution::reorderList(ListNode *head){
	if (!head) return;
	ListNode *pre = head;
	ListNode *last = head;
	ListNode *temp = head;

	int num_list = 0;
	while(pre){
		//统计list节点个数
		pre = pre->next;
		num_list++;
	}
	pre = head;

	for(int i = 0; i < num_list / 2; i++){
		for(int j = 0; j < num_list - 2 * i - 1; j++){
			last = last->next;
		}
		temp = pre->next;
		pre->next = last;
		last->next = temp;
		pre = temp;
		last = pre;
	}
	temp->next = NULL;
}

int main(){
	ListNode *head,*_head;
	_head = new ListNode(0);
	head = _head;
	for(int i = 1; i < 50000; i++){
		_head->next = new ListNode(i);
		_head = _head->next;
	}

	Solution sol;
	//head = nullptr;
	sol.reorderList(head);
	while(head){
		cout << head->val;
		head = head->next;
	}
	return 0;
}