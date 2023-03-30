// https://leetcode.com/problems/brightest-position-on-street/description/

class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        map<int,int> mp;
        for(auto light: lights){
            mp[light[0]-light[1]]++;
            mp[light[0]+light[1]+1]--;
            mp[light[0]+light[1]];
        }
        int ansidx = -1;
        int maxlights = 0;
        int currlights = 0;
        for(auto kv:mp){
            currlights += kv.second;
            if(currlights>maxlights){
                ansidx = kv.first;
                maxlights = currlights;
            }
        }
        return ansidx;
    }
};
