//Hint: Must be 3 consecutive numbers in sorted array that can form a triangle!
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        for(int i=A.size()-1;i>=2;i--)
            if(A[i]<A[i-1]+A[i-2]) return A[i] + A[i-1] + A[i-2];
        return 0;
    }
};
