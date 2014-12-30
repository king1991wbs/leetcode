#Compare two version numbers version1 and version1.
#If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
#
#You may assume that the version strings are non-empty and contain only digits and the . character.
#The . character does not represent a decimal point and is used to separate number sequences.
#For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
#
#Here is an example of version numbers ordering:
#
#0.1 < 1.1 < 1.2 < 13.37
class Solution:
    # @param version1, a string
    # @param version2, a string
    # @return an integer
    def compareVersion(self, version1, version2):
	    ver1 = version1.split('.')
	    #print(ver1)
	    ver2 = version2.split('.')
	    len1 = len(ver1)
	    len2 = len(ver2)
	    len_min = min(len1,len2)

	    for i in range(len_min):
		    if int(ver1[i]) > int(ver2[i]):
			    return 1
		    elif int(ver1[i]) < int(ver2[i]):
			    return -1
	    
	    if len1 > len2:
		    for j in range(len2,len1):
			    if int(ver1[j]) != 0:
				    return 1
		    return 0
	    if len1 < len2:
		    for j in range(len1,len2):
			    if int(ver2[j]) != 0:
				    return -1
		    return 0
	    return 0

sol = Solution()
num = sol.compareVersion('1.3.0','1.3')
print(num)
