class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, lmx = 0, rmx = height.size() - 1;
        int res = 0, area = 0;
        while(left<right)
        {
            if(height[left]>height[lmx])
                lmx = left;
            if(height[right]>height[rmx])
                rmx = right;
            area = min(height[lmx], height[rmx]) * (rmx - lmx);
            if(area>res) res = area;
            if(height[left]<=height[right]) ++left;
            else --right;
        }
        return res;
    }
};
