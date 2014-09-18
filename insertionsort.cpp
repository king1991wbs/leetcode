#include <iostream>

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return head;
        ListNode *pre, *next, *_head;
        _head = head;
        pre = head;
        next = pre->next;

        if (head->val > head->next->val)
        {
            int tem = head->val;
            head->val = head->next->val;
            head->next->val = tem;
        }
        head = head->next->next;//从第三个元素开始比较
        _head->next->next = NULL;
        while (head)
        {
            pre = _head;
            next = pre->next;
            while (next != NULL && head->val > next->val)
            {
                pre = next;
                next = next->next;
            }

            ListNode *temp;
            /*if (next == NULL)
            {
                temp = head->next;
                pre->
                continue;
            }*/
            
            if (pre == _head && head->val < pre->val)
            {
                temp = head->next;
                head->next = pre;
                _head = head;
                head = temp;
                continue;
            }
            temp = head->next;
            pre->next = head;
            head->next = next;
            head = temp;
        }

        return _head;
    }
};

int main()
{
    ListNode *head = new ListNode(4);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(1);
    ListNode *forth = new ListNode(3);
     head->next = second;
     second->next = third;
     third->next = forth;
     forth->next =NULL:

    Solution sol;
    sol.insertionSortList(head);
    return 0;
}