class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word=="") return true;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(board[i][j]==word[0])
                {
                    visited[i][j] = true;
                    if(helper(board, visited, i-1, j, word.substr(1))
                      ||helper(board, visited, i+1, j, word.substr(1))
                      ||helper(board, visited, i, j-1, word.substr(1))
                      ||helper(board, visited, i, j+1, word.substr(1))) return true;
                    else visited[i][j] = false;
                }
            }
        }
        return false;
    }
    
    bool helper(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col, string word)
    {
        if(word=="") return true;
        if(row<0||row>=board.size()) return false;
        if(col<0||col>=board[0].size()) return false;
        if(!visited[row][col]&&board[row][col]==word[0])
        {
            visited[row][col] = true;
            if(helper(board, visited, row-1, col, word.substr(1))
              ||helper(board, visited, row+1, col, word.substr(1))
              ||helper(board, visited, row, col-1, word.substr(1))
              ||helper(board, visited, row, col+1, word.substr(1))) return true;
            else
            {
                visited[row][col] = false;
                return false;
            }
        }
        else return false;
    }
};
