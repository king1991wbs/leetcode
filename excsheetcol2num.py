#Given a column title as appear in an Excel sheet, return its corresponding column number.
#
#For example:
#
#    A -> 1
#    B -> 2
#    C -> 3
#    ...
#    Z -> 26
#    AA -> 27
#    AB -> 28 
class Solution:
    # @param s, a string
    # @return an integer
    def titleToNumber(self, s):
	    s = s[::-1]
	    #print(s)
	    result = 0
	    for i in range(len(s)):
		    result = result + (ord(s[i]) - ord('A') + 1) * (26 ** i)
	    return result

s = "AA"
sol = Solution()
print(sol.titleToNumber(s))
