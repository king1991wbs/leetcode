class Solution {
public:
    void change(vector<vector<char> > &board, int i, int j){
        if(i >= board.size() || j >= board[0].size()) return;
        
        if(board[i][j] == 'O'){
            board[i][j] = '#';
        
            change(board, i-1, j);
            change(board, i+1, j);
            change(board, i, j-1);
            change(board, i, j+1);
        }
        
    }


    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(board.empty()) return;
        
        //change 'O' to '#'
        //up 
        for(int j = 0; j < board[0].size(); j++){
            change(board, 0, j);
        }
        //down 
        for(int j = 0; j < board[0].size(); j++){
            change(board, board.size()-1, j);
        }
        //left
        for(int i = 1; i < board.size() - 1; i++){
            change(board, i, 0);
        }
        //right
        for(int i = 1; i < board.size() - 1; i++){
            change(board, i, board[0].size()-1);
        }
        
        //change 'O' to 'X'
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        
        //change '#' to 'O'
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
        
    }
};
