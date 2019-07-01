//In place
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                int sum = 0;
                if(i>0) sum += board[i-1][j] % 10;
                if(j>0) sum += board[i][j-1] % 10;
                if(i<m-1) sum += board[i+1][j] % 10;
                if(j<n-1) sum += board[i][j+1] % 10;
                if(i>0&&j>0) sum += board[i-1][j-1] % 10;
                if(i>0&&j<n-1) sum += board[i-1][j+1] % 10;
                if(i<m-1&&j>0) sum += board[i+1][j-1] % 10;
                if(i<m-1&&j<n-1) sum += board[i+1][j+1] %10;
                if(sum==3||(sum==2&&board[i][j]==1)) board[i][j] += 10;
            }
        }
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                board[i][j] /= 10;
    }
};

/*Use an intermediate matrix
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> t(m+2, vector<int>(n+2, 0));
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                t[i+1][j+1] = board[i][j];
            }
        }
        for(int i=1;i<m+1;++i) {
            for(int j=1;j<n+1;++j) {
                int sum = t[i-1][j-1]+t[i-1][j]+t[i-1][j+1]+t[i][j-1]+t[i][j+1]+t[i+1][j-1]+t[i+1][j]+t[i+1][j+1];
                if(sum<2||sum>3) board[i-1][j-1] = 0;
                else if(sum==3) board[i-1][j-1] = 1;
            }
        }
    }
};
*/
