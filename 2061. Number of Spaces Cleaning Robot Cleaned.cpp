// https://leetcode.com/problems/number-of-spaces-cleaning-robot-cleaned/description/

class Solution {
public:
    int numberOfCleanRooms(vector<vector<int>>& room) {
        int right = 1;
        int left = 2;
        int up = 4;
        int down = 8;
        int rows = room.size();
        int cols = room[0].size();
        int dir = 1;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                room[i][j] = -1*room[i][j];
            }
        }
        int i = 0, j = 0;
        while(1){
            if((dir&room[i][j])>0){
                break;
            }
            else room[i][j] |= dir;
            if(dir==1){
                if(j+1>=cols || room[i][j+1]==-1){
                    dir = 8;
                }
                else j++;
            }
            else if(dir==2){
                if(j-1<0 || room[i][j-1]==-1){
                    dir = 4;
                }
                else j--;
            }
            else if(dir==4){
                if(i-1<0 || room[i-1][j]==-1){
                    dir = 1;
                }
                else i--;
            }
            else{
                if(i+1>=rows || room[i+1][j]==-1){
                    dir = 2;
                }
                else i++;
            }
        }
        int ans = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(room[i][j]>0){
                    ans++;
                }
            }
        }
        return ans;
    }
};
