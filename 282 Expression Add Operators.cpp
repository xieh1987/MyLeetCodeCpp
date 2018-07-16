class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        DFS(num, target, res, "", 0, 0);
        return res;
    }
    
    void DFS(string num, int target, vector<string>& res, string path, int pos, int prev){
        if(target==0&&pos==num.size()){
            res.push_back(path);
            return;
        }
        long long val = 0;
        for(auto i=pos;i<num.size();++i){
            val = val * 10 + (num[i] - '0');
            if(val>INT_MAX) break;
            if(pos==0) DFS(num, target-val, res, path+to_string(val), i+1, val);
            else{
                DFS(num, target-val, res, path+'+'+to_string(val), i+1, val);
                DFS(num, target+val, res, path+'-'+to_string(val), i+1, -val);
                DFS(num, target+prev-prev*val, res, path+'*'+to_string(val), i+1, prev*val);
            }
            if(num[pos]=='0') break;
        }
    }
};
