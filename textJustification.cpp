/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> rst;
        if( words.empty() )
        	return rst;
        int wordLen = 0;
        int spaceLen = 0;
        auto i = words.begin();
        auto j = i;
        for( ; j != words.end(); j++, spaceLen++ ){
        	wordLen += j->length();
        	if( wordLen + spaceLen > maxWidth ){
        		string str;
        		wordLen -= j->length();
        		spaceLen--;
        		int n = spaceLen ? (maxWidth - wordLen)/spaceLen : 0;
        		int m = spaceLen ? (maxWidth - wordLen)%spaceLen : 0;
        		for( int k = 0; i < j - 1; i++, k++ ){
        			str.append(*i);
        			k < m ? str.append(n + 1, ' ') : str.append(n, ' ');
        		}
        		str.append(*i++);
        		str.append(maxWidth - str.length(), ' ');
        		rst.push_back(str);
        		wordLen = 0;
        		spaceLen = -1;
        		j--;
        	}
        }
        j--;
        spaceLen--;
        string str;
        for( ; i < j; i++ ){
        	str += *i + " ";
        }
        str += *i;
        str.append(maxWidth - wordLen - spaceLen, ' ');
        rst.push_back(str);

		cout << rst.size() << endl;
        for( auto iter : rst )
        	cout << iter << endl;
        return rst;
    }
};

int main(){
	vector<string> words = {"Listen","to","many,","speak","to","a","few."};
	Solution sol;
	sol.fullJustify(words, 6);
	return 0;
}