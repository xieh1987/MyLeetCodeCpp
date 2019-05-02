class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> line(n, 0);
        vector<vector<int>> res(n, line);
        int i=1, nn=n;
        while(nn-1>=n-nn)
        {
            for(int j=n-nn;j<nn;++j)
                res[n-nn][j] = i++;
            if(nn-1!=n-nn)
            {
                for(int j=n-nn+1;j<nn;++j)
                    res[j][nn-1] = i++;
                for(int j=nn-2;j>=n-nn;--j)
                    res[nn-1][j] = i++;
                for(int j=nn-2;j>=n-nn+1;--j)
                    res[j][n-nn] = i++;
            }
            --nn;
        }
        return res;
    }
};
