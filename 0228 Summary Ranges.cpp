class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        vector<string> res;
        if(len==0) return res;
        int head = nums[0], tail = nums[0];
        string t = "";
        for(int i=1;i<len;++i) {
            if(nums[i]==nums[i-1]+1) tail = nums[i];
            else {
                if(head==tail)
                    res.push_back(to_string(head));
                else {
                    t = to_string(head) + "->" + to_string(tail);
                    res.push_back(t);
                }
                head = tail = nums[i];
            }
        }
        if(head==tail) res.push_back(to_string(head));
        else {
            t = to_string(head) + "->" + to_string(tail);
            res.push_back(t);
        }
        return res;
    }
};
