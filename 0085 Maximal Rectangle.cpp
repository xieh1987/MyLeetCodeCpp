class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        int res = 0;
        vector<int> line(n, 0);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                line[j] = matrix[i][j]=='1' ? line[j] + 1 : 0;
            }
            res = max(res, largestRectangle(line));
        }
        return res;
    }
    
    int largestRectangle(vector<int> hist) {
        stack<int> st;
        hist.push_back(0);
        int res = 0;
        for(int i=0;i<hist.size();i++) {
            while(!st.empty()&&hist[i]<hist[st.top()]) {
                int curr = st.top(); st.pop();
                res = max(res, hist[curr] * (st.empty() ? i : (i - 1 - st.top())));
            }
            st.push(i);
        }
        return res;
    }
};
