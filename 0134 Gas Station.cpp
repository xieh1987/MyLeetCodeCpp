class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, index = 0, temp = 0;
        for(int i=0;i<gas.size();i++) {
            sum += gas[i] - cost[i];
            temp += gas[i] - cost[i];
            if(temp<0) {
                index = i + 1;
                temp = 0;
            }
        }
        if(sum>=0) return index;
        else return -1;
    }
};
