// https://leetcode.com/problems/check-if-there-is-a-path-with-equal-number-of-0s-and-1s/description/

class Solution {
public:
    map<pair<pair<int,int>,int>,bool> mp;
    bool helper(int sum, int row, int col, vector<vector<int>>& grid){
        if(row<0 || col<0) return false;
        if(mp.find({{row,col},sum})!=mp.end()) return mp[{{row,col},sum}];
        if(sum<0) return false;
        if(row==0 && col==0){
            if(sum!=grid[0][0]) return false;
            else return true;
        }
        bool ans = helper(sum-grid[row][col],row-1,col,grid);
        ans = ans | helper(sum-grid[row][col],row,col-1,grid);
        mp[{{row,col},sum}] = ans;
        return mp[{{row,col},sum}];
    }
    bool isThereAPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if((rows+cols-1)%2==1) return false;
        int sum_need = (rows+cols-1)/2;
        return helper(sum_need, rows-1, cols-1, grid);
    }
};
