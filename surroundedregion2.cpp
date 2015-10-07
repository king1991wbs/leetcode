#include <iostream>
#include <vector>

using namespace std;


///
///using bfs instead of dfs
///
///
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty())
        	return;

        int i = 0, j = 0;
        //up
        for(i = 0, j = 0; j < board[0].size(); j++)
        {
        	if(board[i][j] == 'O')
        		flip2S(board, i, j);
        }
        //down
        for(i = board.size()-1, j = 0; j < board[0].size(); j++)
        {
        	if(board[i][j] == 'O')
        		flip2S(board, i, j);
        }
        //left
        for(i = 1, j = 0; i < board.size()-1; i++)
        {
        	if(board[i][j] == 'O')
        		flip2S(board, i, j);
        }
        //right
        for(i = 1, j = board[0].size()-1; i < board.size()-1; i++)
        {
        	if(board[i][j] == 'O')
        		flip2S(board, i, j);
        }

        //flip o to x
        //flip S to O
        for(i = 0; i < board.size(); i++)
        	for(j = 0; j < board[0].size(); j++)
        	{
        		if(board[i][j] == 'O')
        			board[i][j] = 'X';
        		if(board[i][j] == 'S')
        			board[i][j] = 'O';
        	}
        //
    }

    void flip2S(vector<vector<char>> & board, int i, int j){
    	board[i][j] = 'S';

    	typedef pair<int, int> location;
    	location loc(i,j);
    	queue<location> locs;
    	locs.push(loc);

    	auto extend_loc = [&](const location & loc){
			vector<location> rst;
    		const int i = loc.first;
    		const int j = loc.second;
    		//up
	    	if((i-1) >= 0 && board[i-1][j] == 'O')
	    	{
	    		board[i-1][j] = 'S';
	    		rst.push_back(make_pair(i-1, j));
	    	}
	    	//down
	    	if((i+1) < board.size() && board[i+1][j] == 'O')
	    	{
	    		board[i+1][j] = 'S';
	    		rst.push_back(make_pair(i+1, j));
	    	}
	    	//left
	    	if((j-1) >= 0 && board[i][j-1] == 'O')
	    	{
	    		board[i][j-1] = 'S';
	    		rst.push_back(make_pair(i, j-1));
	    	}
	    	//right
	    	if((j+1) < board[0].size() && board[i][j+1] == 'O')
	    	{
	    		board[i][j+1] = 'S';
	    		rst.push_back(make_pair(i, j+1));
	    	}

	    	return rst;
    	};

    	while(!locs.empty())
    	{
    		loc = locs.front();
    		locs.pop();
    		auto newLocs = extend_loc(loc);
    		for(auto s : newLocs)
    			locs.push(s);
    	}
    	
    }
    	
};

int main()
{
	size_t t = 1;
	int i = 1;
	cout << (i-1 >= 0);
	return 0;
}