// https://leetcode.com/problems/walls-and-gates/description/

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int rows = rooms.size();
        int cols = rooms[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(rooms[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int currdis = 1;
        while(!q.empty()){
            int qsize = q.size();
            for(int i=0;i<qsize;i++){
                auto qtop = q.front();
                q.pop();
                int x = qtop.first;
                int y = qtop.second;
                if(x-1>=0 && rooms[x-1][y]==INT_MAX){
                    rooms[x-1][y] = currdis;
                    q.push({x-1,y});
                }
                if(y-1>=0 && rooms[x][y-1]==INT_MAX){
                    rooms[x][y-1] = currdis;
                    q.push({x,y-1});
                }
                if(x+1<rows && rooms[x+1][y]==INT_MAX){
                    rooms[x+1][y] = currdis;
                    q.push({x+1,y});
                }
                if(y+1<cols && rooms[x][y+1]==INT_MAX){
                    rooms[x][y+1] = currdis;
                    q.push({x,y+1});
                }
            }
            currdis++;
        }
    }
};
