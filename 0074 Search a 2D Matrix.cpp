class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int left = 0, right = matrix.size() - 1, mid = left + (right - left + 1) / 2;
        while(left<right) {
            if(matrix[mid][0]>target) {
                right = mid - 1;
                mid = left + (right - left + 1) / 2;
            }
            else {
                left = mid;
                mid = left + (right - left + 1) / 2;
            }
        }
        int row = left;
        left = 0, right = matrix[0].size() - 1, mid = left + (right - left) / 2;
        while(left<=right) {
            if(matrix[row][mid]==target) return true;
            if(matrix[row][mid]>target) {
                right = mid - 1;
                mid = left + (right - left) / 2;
            }
            else {
                left = mid + 1;
                mid = left + (right - left) / 2;
            }
        }
        return false;
    }
};
