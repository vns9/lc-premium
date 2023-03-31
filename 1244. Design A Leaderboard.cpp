// https://leetcode.com/problems/design-a-leaderboard/description/

class Leaderboard {
public:
    map<int,int> mp;
    map<int,int> mp1;
    Leaderboard() {
    
    }
    
    void addScore(int playerId, int score) {
        if(mp.find(playerId)==mp.end()){
            mp[playerId] = score;
            mp1[-1*score]++;
        }
        else{
            mp1[-1*mp[playerId]]--;
            mp[playerId] += score;
            mp1[-1*mp[playerId]]++;
        }
    }
    
    int top(int K) {
        int rem = K;
        int ans = 0;
        for(auto kv: mp1){
            int curr = min(rem, kv.second);
            ans += curr*kv.first;
            rem -= curr;
            if(rem==0) break;
        }
        return -1*ans;
    }
    
    void reset(int playerId) {
        mp1[-1*mp[playerId]]--;
        mp[playerId]=0;
        mp1[0]++;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
