class Solution {
    public long[] minimumCosts(int[] regular, int[] express, int expressCost) {
        int n = regular.length;
        long[][] dp = new long[n+1][2];
        dp[0][0] = 0;
        dp[0][1] = expressCost;
        for(int i=1; i<=n; i++){
            dp[i][0] = Math.min(dp[i-1][0]+regular[i-1], dp[i-1][1]+express[i-1]);
            dp[i][1] = Math.min(dp[i-1][1]+express[i-1], dp[i-1][0]+regular[i-1]+expressCost);
        }
        long[] answer = new long[n];
        for(int i=1; i<(n+1); i++){
            answer[i-1] = Math.min(dp[i][0], dp[i][1]);
        }
        return answer;
    }
}