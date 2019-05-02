class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> mystack;
        int ans = 0, start = 0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]==')')
            {
                if(mystack.empty())
                    start = i + 1;
                else
                {
                    mystack.pop();
                    if(!mystack.empty())
                        ans = max(ans, i - mystack.top());
                    else
                        ans = max(ans, i - start + 1);
                }
            }
            else
                mystack.push(i);
        }
        return ans;
    }
};
