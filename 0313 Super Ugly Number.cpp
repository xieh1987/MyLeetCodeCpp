class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(1, 1);
        int len = primes.size();
        vector<int> id(len, 0);
        while(res.size()<n){
            int mn = INT_MAX;
            for(auto i=0;i<len;++i){
                mn = mn<primes[i]*res[id[i]]? mn : primes[i]*res[id[i]];
            }
            for(auto i=0;i<len;++i){
                if(mn==primes[i]*res[id[i]])
                    ++id[i];
            }
            res.push_back(mn);
        }
        return res[n-1];
    }
};
