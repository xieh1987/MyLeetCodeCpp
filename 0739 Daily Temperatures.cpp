class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n, 0);
        stack<int> st;
        for(int i=0;i<n;++i) {
            while(!st.empty()&&T[i]>T[st.top()]) {
                int t = st.top();
                st.pop();
                res[t] = i - t;
            }
            st.push(i);
        }
        return res;
    }
};
