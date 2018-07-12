class Solution {
public:
    string removeDuplicateLetters(string s) {
        int m[128] = {0}, visited[128] = {0};
        string res = "0";
        for(auto l : s) ++m[l];
        for(auto l : s){
            --m[l];
            if(visited[l]) continue;
            while(l<res.back()&&m[res.back()]){
                visited[res.back()] = 0;
                res.pop_back();
            }
            res += l;
            visited[l] = 1;
        }
        return res.substr(1);
    }
};
