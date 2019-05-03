class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> cand;
        int len = nums.size();
        
        for(int i=0; i!=len; ++i){
            if(!cand.empty()&&cand.front()==i-k)
                cand.pop_front();
            while(!cand.empty()&&nums[cand.back()]<=nums[i])
                cand.pop_back();
            cand.push_back(i);
            if(i>=k-1)
                res.push_back(nums[cand.front()]);
        }
        return res;
    }
};
