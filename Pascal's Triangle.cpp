class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        for (int i=0;i<numRows;++i) {
            vector<int> row;
            if (i==0) row.push_back(1);
            else {
                for (int j=0;j<=i;++j) {
                    if (j==0||j==i) row.push_back(1);
                    else row.push_back(res[i-1][j-1]+res[i-1][j]);
                }
            }
            res.push_back(row);
        }
        return res;
    }
};
