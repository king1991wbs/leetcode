//Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
//
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
//For example,
//X X X X
//X O O X
//X X O X
//X O X X
//After running your function, the board should be:
//
//X X X X
//X X X X
//X X X X
//X O X X
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution{
public:
	void solve(vector<vector<char>> &board){
		if(!board.size()) return;

		int row = board.size();
		int col = board[0].size();

		direction come = LEFT;
		for(int i = 0; i < row; ++i){
			for(int j = 0; j < col; ++j){
				if(board[i][j] == 'O')
					isSurround(i, j, come, board);
			}
		}

		for(int i = 0; i < row; ++i){
			for(int j = 0; j < col; ++j){
				if(board[i][j] == 'n')
					board[i][j] = 'O';
			}
		}
	}
private:
	stack<pair<int,int>> cache;
	enum direction{LEFT,UP,RIGHT,DOWN};
private:
	bool isSurround(int,int,direction,vector<vector<char>>&);
	void dealStack(char c, vector<vector<char>> &board){
		while(!cache.empty()){
			pair<int,int> p = cache.top();
			cache.pop();
			board[p.first][p.second] = c;
		}
	}
};

bool Solution::isSurround(int i, int j, direction come, vector<vector<char>> &board){
	board[i][j] = 't';
	cache.push(make_pair(i,j));
	//fangdaowaimian
	if(j == 0 || j == (board[0].size() - 1) || i == 0 || i == (board.size() - 1)){
		dealStack('n', board);
		return false;
	}
	if(come != LEFT){	
		if(board[i][j-1] == 'O' && !isSurround(i,j-1,RIGHT,board)){
			dealStack('n', board);
			return false;
		}
	}
	if(come != UP){
		if(board[i-1][j] == 'O' && !isSurround(i-1,j,DOWN,board)){
			dealStack('n', board);
			return false;
		}
	}
	if(come != RIGHT){
		if(board[i][j+1] == 'O' && !isSurround(i,j+1,LEFT,board)){
			dealStack('n', board);
			return false;
		}
	}
	if(come != DOWN){
		if(board[i+1][j] == 'O' && !isSurround(i+1,j,UP,board)){
			dealStack('n', board);
			return false;
		}
			
	}

	dealStack('X', board);
	return true;
}

int main(){
	vector<vector<char>> board;
	
	vector<char> row ;//= {'O','O','O','O','O','O'};
	for(int i = 0; i < 300; ++i)
		row.push_back('O');
	board.push_back(row);
	vector<char> row2;//= {'O','X','X','X','X','O'};
	row2.push_back('O');
	for(int i = 0; i < 298; ++i)
		row2.push_back('X');
	row2.push_back('O');
	board.push_back(row2);

	vector<char> row3;// = {'O','X','O','O','X','O'};
	row3.push_back('O');row3.push_back('X');
	for(int i = 0; i < 296; ++i)
		row3.push_back('O');
	row3.push_back('X');row3.push_back('O');
	for(int i = 0; i < 296; ++i)
		board.push_back(row3);
	board.push_back(row2);
	board.push_back(row);
	//board.push_back(row2);
	//board.push_back(row);
	//vector<char> row4 = {'X','O','X','X'};
	//board.push_back(row4);

	Solution sol;
	sol.solve(board);
	for(int i = 0; i < board.size(); ++i){
		for(int j = 0; j < board[0].size(); ++j){
			cout << board[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}
