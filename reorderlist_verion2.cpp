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
	//只有一个节点直接返回
	if (num_list == 1) return;
	former_head = head;
	int count = num_list / 2 - 1;
	while(count--){
		latter_head = latter_head->next;
	}
	
	if(num_list % 2){
		//奇数情况
		latter_head = latter_head->next;
	}
	latter_temp = latter_head;
	latter_head = latter_head->next;
	latter_temp->next = NULL;

	//将后半部分逆序
	ListNode *latter_temp_temp = NULL;
	if(latter_head->next){//只有一个元素情况
		latter_temp = latter_head->next;
		latter_temp_temp = latter_temp->next;
		while(latter_temp_temp){
			latter_temp->next = latter_head;
			latter_head = latter_temp;
			latter_temp = latter_temp_temp;
			latter_temp_temp = latter_temp_temp->next;
		}
		latter_temp->next = latter_head;
		latter_head = latter_temp;
	}

	//将前后两个部分拼接起来
	count = num_list / 2 - 1;
	former_temp = former_head->next;
	latter_temp = latter_head->next;
	while(count--){
		latter_head->next = former_temp;
		former_head->next = latter_head;
		former_head = former_temp;
		former_temp = former_temp->next;
		latter_head = latter_temp;
		latter_temp = latter_temp->next;
	}
	latter_head->next = former_temp;
	former_head->next = latter_head;
}

int main(){
	ListNode *head,*_head;
	_head = new ListNode(0);
	head = _head;
	for(int i = 1; i < 1; i++){
		_head->next = new ListNode(i);
		_head = _head->next;
	}

	Solution sol;
	//head = nullptr;
	sol.reorderList(head);
	while(head){
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}