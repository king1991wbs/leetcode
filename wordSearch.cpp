/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
		int row = board.size();
		int col = board[0].size();

		for( int i = 0; i < row; i++ ){
			for( int j = 0 ; j < col; j++){
				bool rst = exists(board, word, i, j, 0);
				if(rst)
					return true;
			}
		}
		return false;
    }
private:
	bool exists( vector<vector<char> > & board, string & word, int i, int j, int idx){
		if( i >= board.size() || j >= board[0].size() 
			|| i < 0 || j < 0 )
			return false;//out of range
		if( board[i][j] == '0' || board[i][j] != word[idx] )
			return false;//been visited or not match
		idx++;
		if( idx == word.size() )
			return true;//match
		char temp = board[i][j];
		board[i][j] = '0';//been visited
		bool rst;
		//right
		rst = exists(board, word, i, j + 1, idx);
		if(rst)
			return true;
		//down
		rst = exists(board, word, i + 1, j, idx);
		if(rst)
			return true;
		//left
		rst = exists(board, word, i, j - 1, idx);
		if(rst)
			return true;
		//up
		rst = exists(board, word, i - 1, j, idx);
		board[i][j] = temp;
		return rst;
	}
};

int main(){
	string word = "SEECS";
	vector<vector<char> > board = {
		{'A','B','C','E'},
  		{'S','F','C','S'},
  		{'A','D','E','E'}
	};
	Solution sol;
	bool rst = sol.exist(board, word);
	if(rst)
		cout << "exist" << endl;
	else
		cout << "not exist" << endl;
	
	return 0;
}