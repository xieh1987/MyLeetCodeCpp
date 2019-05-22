//Define compare function using lambda expression:
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {return to_string(a)+to_string(b)>to_string(b)+to_string(a);});
        string res;
        for(auto v : nums) {
            res += to_string(v);
        }
        return res[0]=='0'? "0" : res;
    }
};

/* Recursion: TLE
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string zero(nums.size(), '0');
        string res, s;
        helper(nums, res, s, 0);
        if(res==zero) res = "0";
        return res;
    }
    
    void helper(vector<int>& nums, string& res, string& s, int k) {
        if(k==nums.size()) {
            res = res<s ? s : res;
            return;
        }
        int len = s.size();
        for(int i=k;i<nums.size();++i) {
            swap(nums[i], nums[k]);
            s += to_string(nums[k]);
            helper(nums, res, s, k+1);
            s = s.substr(0, len);
            swap(nums[i], nums[k]);
        }
    }
};
*/
