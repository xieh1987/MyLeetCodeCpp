class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        getCombination(candidates, target, res, curr, 0);
        return res;
    };
    
    void getCombination(vector<int> candidates, int target, vector<vector<int>>& res, vector<int>& curr, int index){
        if(!target){
            res.push_back(curr);
            return;
        }
        for(int i=index;i<candidates.size()&&target>=candidates[i];++i){
            if(i>index&&candidates[i]==candidates[i-1]) continue; //remove possible duplicates
            curr.push_back(candidates[i]);
            getCombination(candidates, target-candidates[i], res, curr, i+1); //start from i+1, cannot use i multiple times
            curr.pop_back();
        }
    }
};
