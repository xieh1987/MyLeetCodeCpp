class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for(int i=0;i<flowerbed.size();++i){
            if(flowerbed[i]==0){
                int left = i==0? 0 : flowerbed[i-1];
                int right = i+1==flowerbed.size()? 0 : flowerbed[i+1];
                if(!left&&!right){
                    ++count;
                    ++i;
                }
            }
        }
        return count>=n;
    }
};
