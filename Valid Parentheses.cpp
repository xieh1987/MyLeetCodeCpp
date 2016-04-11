class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        for (int i=0;i<s.size();++i) {
            if (s[i]=='('||s[i]=='['||s[i]=='{') mystack.push(s[i]);
            else {
                if (s[i]==')') {
                    if (!mystack.empty()&&mystack.top()=='(') mystack.pop();
                    else return false;
                }
                if (s[i]==']') {
                    if (!mystack.empty()&&mystack.top()=='[') mystack.pop();
                    else return false;
                }
                if (s[i]=='}') {
                    if (!mystack.empty()&&mystack.top()=='{') mystack.pop();
                    else return false;
                }
            }
        }
        return mystack.empty();
    }
};
