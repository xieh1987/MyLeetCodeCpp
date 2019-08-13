class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        bool xwin = false, owin = false;
        int turn = 0, diag = 0, antidiag = 0;
        vector<int> row(3);
        vector<int> col(3);
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board[i][j]=='X') {
                    turn++; row[i]++; col[j]++;
                    if(i==j) diag++;
                    if(i+j==2) antidiag++;
                }
                if(board[i][j]=='O') {
                    turn--; row[i]--; col[j]--;
                    if(i==j) diag--;
                    if(i+j==2) antidiag--;
                }
            }
        }
        xwin = row[0]==3 || row[1]==3 || row[2]==3 ||
               col[0]==3 || col[1]==3 || col[2]==3 ||
               diag==3 || antidiag==3;
        owin = row[0]==-3 || row[1]==-3 || row[2]==-3 ||
               col[0]==-3 || col[1]==-3 || col[2]==-3 ||
               diag==-3 || antidiag==-3;
        if((xwin && turn==0) || (owin && turn==1)) return false;
        if((xwin && owin) || turn<0 || turn>1) return false;
        return true;
    }
};
