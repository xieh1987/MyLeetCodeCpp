class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1;
        while(i<j){
            if(numbers[i]+numbers[j]<target) ++i;
            else if(numbers[i]+numbers[j]>target) --j;
            else break;
        }
        vector<int> res;
        res.push_back(i+1);
        res.push_back(j+1);
        return res;
    }
};
