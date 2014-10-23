#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
	public:
		int solveNQueens(int n){
			//vector<vector<string> > result;
			int num = 0;
			vector<vector<int> > cheesBoard(n, vector<int>(n, 0));
			//for(int j = 0; j < n; j++){
			posQueen(0, 0, cheesBoard, num);
			//}

			return num;
		}
	private:
		void posQueen(int, int, vector<vector<int> > &, int &);
		bool isOk(int, int, vector<vector<int> >);
};

void Solution::posQueen(int i, int j, vector<vector<int>> &chessBoard, int &num){
	if(i == chessBoard.size()){
		num++;
		return;
	}

	while(j < chessBoard.size()){
		if(isOk(i, j, chessBoard)){
			chessBoard[i][j] = 1;
			posQueen(i + 1, 0, chessBoard, result);
			chessBoard[i][j] = 0;
		}
		++j;
	}
}

bool Solution::isOk(int i, int j, vector<vector<int> > chessBoard){
	for(int row = 0; row < i; ++row){
		if(chessBoard[row][j] == 1)	return false;
	}

	for(int row = i, col = j; row >= 0 && col >= 0; --row, --col){
		if(chessBoard[row][col] == 1) return false;
	}
	for(int row = i, col = j; row >= 0 && col < chessBoard.size(); --row, ++col ){
		if(chessBoard[row][col] == 1) return false;
	}
	return true;
}

//int main()
//{
//	Solution sol;
//	sol.solveNQueens(9);
//	return 0;
//}