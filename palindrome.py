#Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
#
#For example,
#"A man, a plan, a canal: Panama" is a palindrome.
#"race a car" is not a palindrome.
#
#Note:
#Have you consider that the string might be empty? This is a good question to ask during an interview.
#
#For the purpose of this problem, we define empty string as valid palindrome.
class Solution:
# @param s, a string
# @return a boolean
	def isPalindrome(self, s):
		s = s.lower()
		l = [c for c in s if c.isalnum()]
		#s = ''.join(l)
		length = len(l)
		if length == 0 or length == 1:
			return True
		
		start = 0
		end = length - 1
		while start < end:
			if(l[start] != l[end]):
				return False
			start += 1
			end   -= 1
		return True
