// https://leetcode.com/problems/number-of-corner-rectangles/description/

class Solution {
public:
    map<pair<int,int>,int> mp;
    int countCornerRectangles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i=0;i<rows;i++){
            vector<int> ones;
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    for(auto el: ones){
                        mp[{el,j}]++;
                    }
                    ones.push_back(j);
                }
            }
        }
        int ans = 0;
        for(auto kv: mp){
            ans+=((kv.second)*(kv.second-1)/2);
        }
        return ans;
    }
};
