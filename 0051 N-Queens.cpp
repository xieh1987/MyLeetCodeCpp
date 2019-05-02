class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> colID(n);
        helper(res, colID, 0);
        return res;
    }
    
    void helper(vector<vector<string>>& res, vector<int>& colID, int row){
        int len = colID.size();
        if(row==len){
            vector<string> solution(len);
            for(auto i=0;i<len;++i){
                string r(len, '.');
                r[colID[i]] = 'Q';
                solution[i] = r;
            }
            res.push_back(solution);
            return;
        }
        for(auto i=0;i<len;++i){
            colID[row] = i;
            if(check(colID, row))
                helper(res, colID, row+1);
        }
    }
    
    bool check(vector<int>& colID, int row){
        for(auto i=0;i<row;++i){
            if((colID[i]==colID[row])||(abs(colID[i]-colID[row])==abs(i-row))) return false;
        }
        return true;
    }
};
