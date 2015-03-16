/*************************************************************************
	> File Name: reversebit.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Tue 01 Apr 2014 10:35:33 AM CST
 ************************************************************************/
/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?
*/

#include<iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i < 32; ++i){
        	result <<= 1;
        	if(n & 1){
        		result = result | 1;
        	}
        	n >>= 1;
        }
       
        return result;
    }
};


int main()
{
	Solution sol;
	cout << sol.reverseBits(2147483648);
    return 0;
}
