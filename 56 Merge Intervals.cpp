class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for(int i=0;i<intervals.size();++i)
        {
            vector<int> temp = intervals[i];
            for(int j=i+1;j<intervals.size();++j)
            {
                if(temp[1]>=intervals[j][0])
                {
                    temp[1] = temp[1]>intervals[j][1]?temp[1]:intervals[j][1];
                    ++i;
                }
                else break;
            }
            res.push_back(temp);
        }
        return res;
    }
};
