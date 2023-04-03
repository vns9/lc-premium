// https://leetcode.com/problems/minimum-health-to-beat-game/description/

class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long ans = 1;
        long long maxdam = 0;
        for(auto el: damage){
            ans+=el;
            if(el>maxdam) maxdam = el;
        }
        ans -= maxdam;
        if(maxdam>armor){
            ans += (maxdam-armor);
        }
        return ans;
    }
};
