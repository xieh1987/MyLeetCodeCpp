class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n1, n2, t;
        for(int i=0;i<tokens.size();++i) {
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/") {
                n1 = st.top();
                st.pop();
                n2 = st.top();
                st.pop();
                if(tokens[i]=="+") t = n1 + n2;
                else if(tokens[i]=="-") t = n2 - n1;
                else if(tokens[i]=="*") t = n1 * n2;
                else t = n2 / n1;
                st.push(t);
            }
            else {
                t = stoi(tokens[i]);
                st.push(t);
            }
        }
        return st.top();
    }
};
