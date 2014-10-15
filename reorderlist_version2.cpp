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

	ListNode *former_head = head, *latter_head = head;
	ListNode *former_temp = head, *latter_temp = head;

	//统计元素个数
	int num_list = 0;
	while(former_head){
		num_list++;
		former_head = former_head->next;
	}
	former_head = head;
	int count = num_list / 2;
	while(count--){
		latter_head = latter_head->next;
	}
	//奇数情况
	if(num_list % 2){
		latter_temp = latter_head;
		latter_head = latter_head->next;
		latter_temp->next = NULL;
	}
	bool first = true;
	for(int i = 0; i < num_list / 2; i++){
		for(int j = 0; j < num_list / 2 - 1 - i; j++){
			former_temp = former_temp->next;
		}
		latter_temp = latter_head;
		latter_head = latter_head->next;
		latter_temp->next = former_temp->next;
		former_temp->next = latter_temp;
		//不是第一次，也不是奇数情况
		if(first && (num_list % 2 != 1)){
			latter_temp->next = nullptr;
			first = false;
		}
		former_temp = former_head;
	}
}

int main(){
	ListNode *temp = nullptr,*head = new ListNode(0);
	temp = head;
	for(int i = 1; i < 1; i++){
		head->next = new ListNode(i);
		head = head->next;
	}

	Solution sol;
	head = temp;
	head = nullptr;
	sol.reorderList(head);
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}