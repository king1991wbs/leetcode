#include <iostream>

using std::swap;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *sortList(ListNode *head) {
		if(head == NULL || head->next == NULL) return head;
		
		ListNode *start,*end;
		start = head;
		while(start->next) start = start->next;
		end = start;

		_aux_sortList(head, end);

		return head;
    }
private:
	void _aux_sortList(ListNode *start, ListNode *end);
	ListNode* partition(ListNode *start, ListNode *end);
};

void Solution::_aux_sortList(ListNode *start, ListNode *end)
{
	ListNode *p, *s;
	s = start;
	if(!start || !end || start == end) return;
	while(s != end && s != NULL) s = s->next;
	if(s != end) return;

	p = partition(start, end);
	s = start;
	if(p == start)
	{
		_aux_sortList(p->next, end);
	}
	else
	{
		while(s->next != p)
			s = s->next;
		_aux_sortList(start, s);
		_aux_sortList(s->next->next, end);
	}
}

ListNode* Solution::partition(ListNode *start, ListNode *end)
{
	ListNode *_start = start;//, *temp = start;
	//if(start->val < end->val)
	//{
	//	//swap(start->val, _start->val);
	//	start = start->next;
	//}
	while(start != end)
	{
		if(start->val < end->val)
		{
			swap(start->val, _start->val);
			_start = _start->next;
		}
		start = start->next;			
	}
	swap(_start->val, end->val);

	/*while(temp->next != _start) 
		temp = temp->next;*/

	return _start;
}

int main()
{
	ListNode *head = new ListNode(0);
	ListNode *second = new ListNode(1);
	head->next = second;
	/*ListNode *third = new ListNode(3);
	second->next = third;
	ListNode *forth = new ListNode(4);
	third->next = forth;*/
	ListNode *temp;
	int n = 5500;
	for(int i = 2; i < n; i++)
	{
		temp = new ListNode(i);
		second->next = temp;
		second = temp;
	}
	Solution sol;
	sol.sortList(head);
	return 0;
}