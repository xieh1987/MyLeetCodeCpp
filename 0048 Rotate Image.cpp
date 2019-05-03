class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        int m = (len + 1) / 2, n = len / 2;
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[len-1-j][i];
                matrix[len-1-j][i] = matrix[len-1-i][len-1-j];
                matrix[len-1-i][len-1-j] = matrix[j][len-1-i];
                matrix[j][len-1-i] = temp;
            }
        }
    }
};
