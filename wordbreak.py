class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a boolean
    def wordBreak(self, s, dict):
        if len(s) == 0:
            return False
        word = s[:1]
        s = s[1:]#del s[:1]
        sentence = []
        sentence.append(word)
        first = True
        while len(sentence):
        	word = sentence.pop()
        	s = word + s
        	#word = s[:len(word)]
        	if first:
        		i = 1
        		first = False
        	else:
        		i = len(word) + 1#set bool
        	#for i in range(wordlen, len(s)):
        	while len(s) >= i:
        		if s in dict:
        			return True
        		word = s[:i]
        		if word in dict:
        			sentence.append(word)
        			s = s[i:]#del s[:i]
        			i = 1
        		else:
        			i += 1
        return False
#import pdb
#pdb.set_trace()
sol = Solution()
sentence = "aaaaaaaaaaaaaaaaaaaaaaaaaaaab"
strings = ["a","aa","aaa"]#,"aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]

print sol.wordBreak(sentence, strings)
