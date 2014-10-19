class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a boolean
    def wordBreak(self, s, dict):
    	if s in dict:
    		return True
        for i in range(1, len(s)):
        	word = s[:i]
        	if word in dict:
        		if self.wordBreak(s[i:], dict) == True:
        			return True
        		else:
        			continue
        return False
sol = Solution()
sentence = "fohhemkkaecojceoaejkkoedkofhmohkcjmkggcmnami"
strings = []
print sol.wordBreak(sentence, strings)