// https://leetcode.com/problems/meeting-rooms-ii/description/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int> mp;
        int ans = 0;
        int roomcnt = 0;
        for(auto interval: intervals){
            mp[interval[0]]++;
            mp[interval[1]-1];
            mp[interval[1]]--;
        }
        for(auto kv: mp){
            roomcnt += kv.second;
            ans = max(ans, roomcnt);
        }
        return ans;
    }
};
