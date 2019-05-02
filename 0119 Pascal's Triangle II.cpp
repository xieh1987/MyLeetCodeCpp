class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res{1};
        for(int row=1;row<=rowIndex;++row){
            res.push_back(1);
            for(int i=row-1;i>0;--i)
                res[i] += res[i-1];
        }
        return res;
    }
};
