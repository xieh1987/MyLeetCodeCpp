class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        vector<vector<int>> hp(row+1, vector<int>(col+1, INT_MAX));
        hp[row-1][col] = 1;
        hp[row][col-1] = 1;
        for(int i=row-1;i>=0;--i){
            for(int j=col-1;j>=0;--j){
                int needed = min(hp[i+1][j], hp[i][j+1])-dungeon[i][j];
                hp[i][j] = needed<1 ? 1 : needed;
            }
        }
        return hp[0][0];
    }
};
