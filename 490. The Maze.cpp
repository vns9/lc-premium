// https://leetcode.com/problems/the-maze/description/

class Solution {
public:
    int rows = 0;
    int cols = 0;
    void dfs(int dir, int x, int y, vector<vector<int>>& maze){
        if(maze[x][y]&dir) return;
        maze[x][y] |= dir;
        if(dir==1){
            if(y-1<0||maze[x][y-1]<0){
                maze[x][y] |= 16;
                dfs(1,x,y,maze);
                dfs(2,x,y,maze);
                dfs(4,x,y,maze);
                dfs(8,x,y,maze);
                
            }
            else{
                dfs(dir, x, y-1, maze);
            }
        }
        else if(dir==2){
            if(y+1>=cols||maze[x][y+1]<0){
                maze[x][y] |= 16;
                dfs(1,x,y,maze);
                dfs(2,x,y,maze);
                dfs(4,x,y,maze);
                dfs(8,x,y,maze);
            }
            else{
                dfs(dir, x, y+1, maze);
            }
        }
        else if(dir==4){
            if(x-1<0||maze[x-1][y]<0){
                maze[x][y] |= 16;
                dfs(1,x,y,maze);
                dfs(2,x,y,maze);
                dfs(4,x,y,maze);
                dfs(8,x,y,maze);
            }
            else{
                dfs(dir, x-1, y, maze);
            }
        }
        else{
            if(x+1>=rows||maze[x+1][y]<0){
                maze[x][y] |= 16;
                dfs(1,x,y,maze);
                dfs(2,x,y,maze);
                dfs(4,x,y,maze);
                dfs(8,x,y,maze);
            }
            else{
                dfs(dir, x+1, y, maze);
            }
        }
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int left = 1;
        int right = 2;
        int up = 4;
        int down = 8;
        int x = start[0];
        int y = start[1];
        rows = maze.size();
        cols = maze[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                maze[i][j] = -1*maze[i][j];
            }
        }
        dfs(1,x,y,maze);
        dfs(2,x,y,maze);
        dfs(4,x,y,maze);
        dfs(8,x,y,maze);
        return (maze[destination[0]][destination[1]]&16);
    }
};
