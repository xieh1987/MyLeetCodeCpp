class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]]=='M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        Reveal(board, click[0], click[1]);
        return board;
    }
    
    void Reveal(vector<vector<char>>& board, const int& row, const int& col) {
        int count = 0;
        for(int i=row-1;i<=row+1;i++){
            for(int j=col-1;j<=col+1;j++){
                if(Isinboard(board,i,j)&&(board[i][j]=='M')&&(i!=row||j!=col))
                    count++;
            }
        }
        if(count==0){
            board[row][col] = 'B';
            for(int i=row-1;i<=row+1;i++){
                for(int j=col-1;j<=col+1;j++){
                    if(i!=row||j!=col)
                        Reveal(board, i, j);
                }
            }
        }
        else board[row][col] = '0' + count;
    }
    
    bool Isinboard(vector<vector<char>> board, int& x, int& y){
        return (x>=0&&y>=0&&x<board.size()&&y<board[0].size());
    }
};

