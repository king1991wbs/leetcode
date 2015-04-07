/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
		int hash[10] = {0};
		int hashcol[10] = {0};
		int hash9[9][10] = {0};
		//行跟3x3小格
		for( int i = 0; i < board.size(); ++i ){
			for( int j = 0; j < board[0].size(); ++j ){
				if( board[i][j] != '.' ){
					cout << board[i][j]  << " " << hash9[i/3*3 + j/3][ board[i][j] - '0' ] << endl;
					hash[ board[i][j] - '0' ]++;
					hash9[i/3*3 + j/3][ board[i][j] - '0' ]++;
					cout << hash[ board[i][j] - '0' ] << " " << hash9[i/3*3 + j/3][ board[i][j] - '0' ] << endl;
					if( hash[ board[i][j] - '0' ] > 1 || hash9[i/3*3 + j/3][ board[i][j] - '0' ] > 1 )
						return false;
				}
				if( board[j][i] != '.' ){
					hashcol[ board[j][i] - '0' ]++;
					if( hashcol[ board[j][i] - '0' ] > 1 )
						return false;
				}
			}
			for( int k = 0; k < 10; ++k ){
				hash[k] = 0;
				hashcol[k] = 0;
			}
		}
		return true;
    }
};

int main(){
	Solution sol;
	vector<vector<char> > v(9, vector<char>(9,'.'));
	for(int i = 8; i > 0; i--){
		v[0][9-i]='0'+i;
	}
	for(int i = 1; i < 9; i++){
		v[i][0]='0' + i+1;
	}
	cout  << sol.isValidSudoku(v);
	return 0;
}