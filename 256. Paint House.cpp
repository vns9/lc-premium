// https://leetcode.com/problems/paint-house/description/

class Solution {
public:
    map<pair<int,int>,int> mp;
    int helper(vector<vector<int>>& costs, int idx, int color){
        if(mp.find({idx,color})!=mp.end()){
            return mp[{idx, color}];
        }
        if(idx==0){
            mp[{idx, color}] = costs[idx][color];
        }
        else{
            mp[{idx, color}] = costs[idx][color]+min(helper(costs, idx-1, (color+1)%3), helper(costs, idx-1, (color+2)%3));
        }
        return mp[{idx, color}];
    }
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int ans = helper(costs,n-1,0);
        ans = min(ans, helper(costs,n-1,1));
        ans = min(ans, helper(costs,n-1,2));
        return ans;
    }
};
