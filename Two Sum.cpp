class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> aMap;
        vector<int> myVec;
        int index=0;
        for(vector<int>::iterator iter=numbers.begin(); iter!=numbers.end(); iter++, index++){
            if(aMap.find(target-*iter)!=aMap.end()){
                myVec.push_back(aMap[target-*iter]+1);
                myVec.push_back(index+1);
                return myVec;
            }
            else{
                aMap.insert(pair<int, int> (*iter, index));
            }
        }
    }
};
