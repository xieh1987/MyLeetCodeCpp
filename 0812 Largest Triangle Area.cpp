class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0.0;
        int m = points.size();
        for(int i=0;i<m-2;i++) {
            for(int j=i+1;j<m-1;j++) {
                for(int k=j+1;k<m;k++) {
                    double area = abs( points[j][0] * points[k][1] - points[i][0] * points[k][1]
                                     - points[j][0] * points[i][1] - points[k][0] * points[j][1]
                                     + points[i][0] * points[j][1] + points[k][0] * points[i][1] ) / 2.0;
                    res = max(res, area);
                }
            }
        }
        return res;
    }
};
