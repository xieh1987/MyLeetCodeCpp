class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        vector<int> temp(newInterval);
        int i=0, length = intervals.size();
        while(i<length)
        {
            if(temp[1]<intervals[i][0])
            {
                res.push_back(temp);
                break;
            }
            else if(temp[0]>intervals[i][1])
                res.push_back(intervals[i++]);
            else
            {
                temp[0] = temp[0]<intervals[i][0]?temp[0]:intervals[i][0];
                temp[1] = temp[1]>intervals[i][1]?temp[1]:intervals[i][1];
                ++i;
            }
        }
        if(i==length) res.push_back(temp);
        while(i<length)
            res.push_back(intervals[i++]);
        return res;
    }
};
