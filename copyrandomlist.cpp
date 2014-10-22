#include <iostream>
#include <map>

using namespace std;

struct RandomListNode{
	int label;
	RandomListNode *next,*random;
	RandomListNode(int x):label(x), next(NULL), random(NULL){}
};

class Solution{
public:
	RandomListNode *copyRandomList(RandomListNode *head){
		if(!head) return head;

		RandomListNode *copy_head = new RandomListNode(head->label);
		//是否保留待定
		if(!head->next){
			copy_head->random = head->random ? copy_head : NULL;
			return copy_head;
		}

		map<RandomListNode*, RandomListNode*> origin, copy;
		origin[head] = head->random;
		copy[head]   = copy_head;
		RandomListNode *_head = head, *_copy_head = copy_head;
		while(head->next){
			copy_head->next = new RandomListNode(head->next->label);
			head = head->next;
			copy_head = copy_head->next;
			origin[head] = head->random;
			copy[head] = copy_head;
		}

		//拷贝random指针
		head = _head;
		copy_head = _copy_head;
		while(head){
			copy_head->random = origin[head] ? copy[origin[head]] : NULL;
			head = head->next;
			copy_head = copy_head->next;
		}

		return _copy_head;
	}
};

int main(){
	RandomListNode *list = new RandomListNode(-1);
	RandomListNode *list1 = new RandomListNode(1);
	list->next = list1;
	list1->random = list;

	Solution sol;
	sol.copyRandomList(list);
	return 0;
}
