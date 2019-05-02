class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<int> colID(n);
        helper(colID, count, n, 0);
        return count;
    }
    
    void helper(vector<int>& colID, int& count, int& n, int row){
        if(row==n){
            ++count;
            return;
        }
        for(auto i=0;i<n;++i){
            colID[row] = i;
            if(check(colID, row))
                helper(colID, count, n, row+1);
        }
    }
    
    bool check(vector<int>& colID, int& row){
        for(auto i=0;i<row;++i){
            if((colID[i]==colID[row])||(abs(row-i)==abs(colID[row]-colID[i]))) return false;
        }
        return true;
    }
};
