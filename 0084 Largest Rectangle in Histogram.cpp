/*Brute force with trim
 *Time complexity O(n^), space complexity O(1)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        for(int i=0;i<heights.size();i++) {
            if(i+1<heights.size()&&heights[i]<=heights[i+1])
                continue;
            int mn = heights[i];
            for(int j=i;j>=0;j--) {
                mn = min(heights[j], mn);
                res = max(res, (i-j+1)*mn);
            }
        }
        return res;
    }
};
*/

//Monotone stack
//Time complexity O(n), space complexity O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int res = 0;
        for(int i=0;i<heights.size();i++) {
            while(!st.empty()&&heights[st.top()]>=heights[i]) {
                int id = st.top(); st.pop();
                res = max(res, heights[id] * (st.empty() ? i : (i - 1 - st.top())));
            }
            st.push(i);
        }
        return res;
    }
};
