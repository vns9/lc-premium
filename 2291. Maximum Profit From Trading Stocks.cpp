// https://leetcode.com/problems/maximum-profit-from-trading-stocks/description/

class Solution {
public:
    int helper(int i, vector<int>& present, vector<int>& future, int budget, vector<vector<int>>& dp){
        if(i==-1) return 0;
        if(dp[i][budget]!=-1) return dp[i][budget];
        int ans = helper(i-1,present,future,budget, dp);
        if(future[i]>present[i] && present[i]<=budget){
            ans = max(ans, future[i]-present[i]+helper(i-1,present,future,budget-present[i],dp));
        }
        dp[i][budget] = ans;
        return dp[i][budget];
    }
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n = present.size();
        vector<vector<int>> dp(n, vector<int>(budget+1,-1));
        return helper(n-1, present, future, budget, dp);
    }
};
