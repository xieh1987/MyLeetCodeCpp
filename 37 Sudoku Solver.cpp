class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0);
    }
    
    bool checkValid(vector<vector<char>>& board, char val, int row, int col)
    {
        for(int i=0;i<9;++i)
        {
            if(col!=i&&board[row][i]==val) return false;
            if(row!=i&&board[i][col]==val) return false;
        }
        int blkrow = row / 3, blkcol = col / 3;
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<3;++j)
            {
                if((blkrow*3+i!=row||blkcol*3+j!=col)&&board[blkrow*3+i][blkcol*3+j]==val) return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int pos)
    {
        if(pos==81) return true;
        int row = pos / 9, col = pos % 9;
        if(board[row][col]!='.')
        {
            if(solve(board, pos+1))
                return true;
        }
        else
        {
            for(int i=0;i<9;++i)
            {
                if(checkValid(board, '1'+i, row, col))
                {
                    board[row][col] = '1' + i;
                    if(solve(board, pos+1)) return true;
                    else board[row][col] = '.';
                }
            }
        }
        return false;
    }
};
