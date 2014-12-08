#Write a program to find the node at which the intersection of two singly
#linked lists begins.


#For example, the following two linked lists:

#A:          a1 ¡ú a2
#                   ¨K
#                     c1 ¡ú c2 ¡ú c3
#                   ¨J            
#B:     b1 ¡ú b2 ¡ú b3
#begin to intersect at node c1.
#
#
#Notes:
#
#If the two linked lists have no intersection at all, return null.
#The linked lists must retain their original structure after the function returns.
#You may assume there are no cycles anywhere in the entire linked structure.
#Your code should preferably run in O(n) time and use only O(1) memory.

import pdb
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param two ListNodes
    # @return the intersected ListNode
    def getIntersectionNode(self, headA, headB):
	if not headA or not headB:
		return None

	numA = 0
        A = headA
	numB = 0
        B = headB
        while headA:
            numA += 1
            headA = headA.next
        while headB:
            numB += 1
            headB = headB.next
	
	if numA > numB:
		while numA != numB:
			A = A.next
			numA -= 1
		while numA != 0:
			if A == B:
				return A
			A = A.next
			B = B.next
			numA -= 1
		return None
	else:
		while numA != numB:
			B = B.next
			numB -= 1
		while numB != 0:
			if A == B:
				return B
			A = A.next
			B = B.next
			numA -= 1
		return None
headA = ListNode(1)
headB = ListNode(1)

sol = Solution()
pdb.set_trace()
print sol.getIntersectionNode(headA,headB)
