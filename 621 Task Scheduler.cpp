class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        if(!len) return 0;
        vector<int> vec(26, 0);
        for(auto t : tasks)
            ++vec[t-'A'];
        sort(vec.begin(), vec.end());
        int i = 25, mx = vec[25];
        while(i>=0&&vec[i]==mx) --i;
        return max(len, (n+1) * (mx-1) + 25 - i);
    }
};
