#include <iostream> 
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		size_t len1 = nums1.size();
		size_t len2 = nums2.size();
		
		bool odd = (len1 + len2) & 0x1;
		int cnt = odd ? (len1+len2)/2 : (len1+len2)/2-1;
		int i = 0, j = 0;
		while(cnt && i < nums1.size() && j < nums2.size())
		{
			if(nums1[i] < nums2[j])
				i++;
			else
				j++;
			cnt--;
		}
		
		if(odd)
		{
			if(i == nums1.size())
			{
				return nums2[j+cnt];
			}
			else if(j == nums2.size())
			{
				return nums1[i+cnt];
			}
			
			return nums1[i] >= nums2[j] ? nums2[j] : nums1[i];
		}
		else
		{
			if(i == nums1.size())
			{
				return (nums2[j+cnt]+nums2[j+cnt+1])/2.0;
			}
			else if(j == nums2.size())
			{
				return (nums1[i+cnt]+nums1[i+cnt+1])/2.0;
			}
			
			int a = 0, b = 0;
			if(nums1[i] < nums2[j])
			{
				a = nums1[i++];
				if(i == len1)
				{
					b = nums2[j];
					return (a+b)/2.0;
				}
				
			}
			else
			{
				a = nums2[j++];
				if(j == len2)
				{
					b = nums1[i];
					return (a+b)/2.0;
				}
				
			}
			if(nums1[i] < nums2[j]) b = nums1[i];
			else	b = nums2[j];
			
			return (a+b)/2.0;
		}
	    
    }
};

int main()
{
	vector<int> nums1 = {1,2};
	vector<int> nums2 = {1,2};
	
	Solution sol;
	cout << sol.findMedianSortedArrays(nums1, nums2);
	return 0;
}
