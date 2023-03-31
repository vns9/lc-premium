// https://leetcode.com/problems/shortest-path-to-get-food/description/

class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int x = -1;
        int y = -1;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='*'){
                    x = i;
                    y = j;
                }
                if(grid[i][j]=='X'){
                    grid[i][j] = '*';
                }
            }
        }
        int dis = 0;
        queue<pair<int,int>> q;
        q.push({x,y});
        while(!q.empty()){
            int qsize = q.size();
            for(int i=0;i<qsize;i++){
                auto ctop = q.front(); 
                q.pop();
                int cx = ctop.first;
                int cy = ctop.second;
                if((cx+1)<rows && grid[cx+1][cy]!='*'){
                    if(grid[cx+1][cy]=='#') return dis+1;
                    grid[cx+1][cy]='*';
                    q.push({cx+1,cy});
                }
                if((cy+1)<cols && grid[cx][cy+1]!='*'){
                    if(grid[cx][cy+1]=='#') return dis+1;
                    grid[cx][cy+1]='*';
                    q.push({cx,cy+1});
                }
                if((cx-1)>=0 && grid[cx-1][cy]!='*'){
                    if(grid[cx-1][cy]=='#') return dis+1;
                    grid[cx-1][cy]='*';
                    q.push({cx-1,cy});
                }
                if((cy-1)>=0 && grid[cx][cy-1]!='*'){
                    if(grid[cx][cy-1]=='#') return dis+1;
                    grid[cx][cy-1]='*';
                    q.push({cx,cy-1});
                }
            }
            dis++;
        }
        return -1;
    }
};
