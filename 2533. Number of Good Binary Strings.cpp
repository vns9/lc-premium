// https://leetcode.com/problems/number-of-good-binary-strings/description/

class Solution {
public:
    int helper(int i, vector<int>& dp, int oneGroup, int zeroGroup){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = 0;
        int v1 = helper(i-oneGroup, dp, oneGroup, zeroGroup)%1000000007;
        ans += v1;
        ans %= 1000000007;
        int v2 = helper(i-zeroGroup, dp, oneGroup, zeroGroup)%1000000007;
        ans += v2;
        ans %= 1000000007;
        dp[i] = ans;
        return dp[i];
    }
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        int n = maxLength;
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        for(int i=minLength;i<=maxLength;i++){
            helper(i,dp,oneGroup,zeroGroup);
        }
        int ans = 0;
        for(int i=minLength;i<=maxLength;i++){
            if(dp[i]!=-1){
                ans += dp[i];
                ans %= 1000000007;
            }
        }
        return ans;
    }
};
