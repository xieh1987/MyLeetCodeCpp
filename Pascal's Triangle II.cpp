class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1);
        res[rowIndex] = 1;
        for (int i=0;i<rowIndex;++i) {
            for(int j=0;j<rowIndex;++j) {
                res[j] += res[j+1];
            }
        }
        return res;
    }
};
