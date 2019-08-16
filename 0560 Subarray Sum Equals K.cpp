//DP + HashTable
//Time: O(n); Space: O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> dp(nums.size()+1, 0);
        unordered_map<int, int> m;
        m[0] = 1;
        int res = 0;
        for(int i=0;i<nums.size();i++) {
            dp[i+1] = dp[i] + nums[i];
            int t = dp[i+1] - k;
            if(m.count(t)) res += m[t];
            m[dp[i+1]]++;
        }
        return res;
    }
};

/*DP + Search
 *Time: O(n^2); Space: O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> dp(nums.size()+1, 0);
        int res = 0;
        for(int i=0;i<nums.size();i++) {
            dp[i+1] = dp[i] + nums[i];
        }
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size()+1;j++)
                if(dp[j]-dp[i]==k)
                    res++;
        }
        return res;
    }
};
*/
