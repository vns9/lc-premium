// https://leetcode.com/problems/choose-edges-to-maximize-score-in-a-tree/description/

class Solution {
public:
    map<int, vector<int>> mp;
    map<pair<int, bool>, long long> dp;
    long long helper(int node, bool flag, vector<vector<int>>& edges){
        if(dp.find({node,flag})!=dp.end()) return dp[{node,flag}];
        long long ans = 0;
        if(flag){
            vector<long long> v1;
            for(int i=0;i<mp[node].size();i++){
                v1.push_back(helper(mp[node][i],true,edges));
            }
            long long total_sum = 0;
            for(auto el: v1){
                total_sum += el;
            }
            for(int i=0;i<mp[node].size();i++){
                long long curr = helper(mp[node][i],false,edges);
                if((curr+total_sum-v1[i]+edges[mp[node][i]][1])>ans) ans = curr+total_sum-v1[i]+edges[mp[node][i]][1]; 
            }
        }
        long long ans2 = 0; 
        for(auto child: mp[node]){
            ans2 += helper(child, true, edges);
        }
        if(ans2>ans) ans = ans2;
        if(ans<0) ans = 0;
        dp[{node,flag}] = ans;
        return dp[{node,flag}];;
    }
    long long maxScore(vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back(i);
        }
        long long v1 = helper(0, true, edges);
        long long v2 = helper(0, false, edges);
        if(v1>v2) return v1;
        return v2;
    }
};
