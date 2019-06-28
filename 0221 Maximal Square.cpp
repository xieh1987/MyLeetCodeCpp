class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        int mx = 0;
        for(auto i=0;i<m;++i) {
            if(matrix[i][0]=='1') res[i][0] = 1;
            else res[i][0] = 0;
            mx = max(mx, res[i][0]);
        }
        for(auto i=0;i<n;++i) {
            if(matrix[0][i]=='1') res[0][i] = 1;
            else res[0][i] = 0;
            mx = max(mx, res[0][i]);
        }
        for(int i=1;i<m;++i) {
            for(int j=1;j<n;++j) {
                if(matrix[i][j]=='0') res[i][j] = 0;
                else res[i][j] = min(res[i-1][j-1], min(res[i][j-1], res[i-1][j])) + 1;
                mx = max(mx, res[i][j]);
            }
        }
        return mx * mx;
    }
};
