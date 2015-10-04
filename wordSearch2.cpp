class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> rst;
        
        if(0 == board.size() || 0 == words.size())
            return vector<string>();

        unordered_set<string> failStr;
        for(auto str : words)
        {
            if(str.size() == 0)
                continue;
            bool fail = false;
            for(auto fails : failStr)
            {
                if(str.find(fails) != string::npos)
                {
                    fail = true;
                    break;
                }
            }
            if(fail) continue;

            bool in = findWordInboard(board, str, failStr);
            if(in)
                rst.insert(str);
        }
        
        return vector<string>(rst.begin(), rst.end());
    }

    bool findWordInboard(vector<vector<char>> & board, const string & str, unordered_set<string> & failStr)
    {
        int maxK = -1;
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
            {
                int k = 0;
                bool in = _findWordInboard(board, i, j, str, k, maxK);
                if(in)
                    return true;
            }
        failStr.insert(str.substr(0, maxK+1));
        return false;
    }

    bool _findWordInboard(vector<vector<char>> & board, int i, int j, const string & str, int k, int & maxK)
    {
        if(k == str.size())
            return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;

        maxK = maxK > k ? maxK : k;
        if(board[i][j] == str[k])
        {
            board[i][j] += 'z';

            bool in = _findWordInboard(board, i-1, j, str, k+1, maxK) || _findWordInboard(board, i+1, j, str, k+1, maxK) ||
            _findWordInboard(board, i, j-1, str, k+1, maxK) || _findWordInboard(board, i, j+1, str, k+1, maxK);

            board[i][j] -= 'z';
            return in;
        }
        return false;
    }
};