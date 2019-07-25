class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = nums1.size() + nums2.size();
        if(l%2) return findKth(nums1, 0, nums2, 0, l / 2 + 1);
        else return (findKth(nums1, 0, nums2, 0, l / 2) + findKth(nums1, 0, nums2, 0, l / 2 + 1)) / 2.0;
    }
    
    int findKth(vector<int>& nums1, int pos1, vector<int>& nums2, int pos2, int k)
    {
        if(pos1>=nums1.size()) return nums2[pos2+k-1];
        if(pos2>=nums2.size()) return nums1[pos1+k-1];
        if(k==1) return min(nums1[pos1], nums2[pos2]);
        int mid = k / 2;
        if(pos1+mid-1>=nums1.size()) return findKth(nums1, pos1, nums2, pos2 + mid, k - mid);
        if(pos2+mid-1>=nums2.size()) return findKth(nums1, pos1 + mid, nums2, pos2, k - mid);
        if(nums1[pos1+mid-1]<=nums2[pos2+mid-1]) return findKth(nums1, pos1 + mid, nums2, pos2, k - mid);
        else return findKth(nums1, pos1, nums2, pos2 + mid, k - mid);
    }
};
