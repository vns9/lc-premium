// https://leetcode.com/problems/toss-strange-coins/description/

class Solution {
public:
    map<pair<int,int>,double> dp;
    double helper(int i, int target, vector<double>& prob){
        if(target>(i+1)) return 0;
        if(i==-1 && target==0) return 1;
        if(dp.find({i,target})!=dp.end()) return dp[{i,target}];
        double ans = 0.0;
        if(target>0) ans = helper(i-1,target-1,prob)*prob[i];
        ans += helper(i-1,target,prob)*(1-prob[i]);
        dp[{i,target}] = ans;
        return dp[{i,target}];
    }
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        return helper(n-1, target, prob);
    }
};
