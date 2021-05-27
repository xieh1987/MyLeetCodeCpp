class NumArray {
public:
    vector<int> num_array = {};
    NumArray(vector<int>& nums) {
        for (auto it=nums.begin();it!=nums.end();++it)
            num_array.push_back(*it);
    }
    
    int sumRange(int left, int right) {
        int res = 0;
        while (left<=right)
        {
            res += this->num_array[left++];
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
