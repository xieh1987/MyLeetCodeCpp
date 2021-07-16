class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "";
        for(auto i=0;i<s.size();++i) {
            if(s[i]==' ') {
                if(word.size()) {
                    st.push(word);
                    word = "";
                }
            }
            else {
                word += s[i];
            }
        }
        if(word.size()) st.push(word);
        string res = "";
        while(!st.empty()) {
            res += " " + st.top();
            st.pop();
        }
        return res.substr(1);
    }
};
