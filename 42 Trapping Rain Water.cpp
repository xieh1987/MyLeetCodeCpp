class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        if(length<1) return 0;
        int ans = 0;
        int lp = 0, rp = length-1, lmx = height[0], rmx = height[length-1];
        while(lp<rp)
        {
            if(height[lp]<height[rp])
            {
                if(height[lp]>lmx) lmx = height[lp];
                else ans += lmx - height[lp];
                ++lp;
            }
            else
            {
                if(height[rp]>rmx) rmx = height[rp];
                else ans += rmx - height[rp];
                --rp;
            }
        }
        return ans;
    }
};
