class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0;i<9;++i) {
                vector<bool> duprow(9, false);
                vector<bool> dupcol(9, false);
            for (int j=0;j<9;++j) {
                if (board[i][j]!='.') {
                    if (board[i][j]-'0'<1||board[i][j]-'0'>9||duprow[board[i][j]-'1']) return false;
                    duprow[board[i][j]-'1'] = true;
                }
                if (board[j][i]!='.') {
                    if (board[j][i]-'0'<1||board[j][i]-'0'>9||dupcol[board[j][i]-'1']) return false;
                    dupcol[board[j][i]-'1'] = true;
                }
            }
        }
        
        for (int i=0;i<9;i+=3) {
            for (int j=0;j<9;j+=3) {
                vector<bool> dupcube(9, false);
                for (int row=i;row<i+3;++row) {
                    for (int col=j;col<j+3;++col) {
                        if (board[row][col]!='.') {
                            if (board[row][col]-'0'<1||board[row][col]-'0'>9||dupcube[board[row][col]-'1']) return false;
                            dupcube[board[row][col]-'1'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};
