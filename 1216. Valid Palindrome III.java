class Solution {
    public int helper(int i, int j, String s, int[][] dp){
        if(dp[i][j] != -1) return dp[i][j];
        if(i==j) return 1;
        if(i>j) return 0;
        int answer = -1;
        if(s.charAt(i) == s.charAt(j)){
            answer = 2+helper(i+1, j-1, s, dp);
        }
        else{
            answer = Math.max(helper(i+1, j, s, dp), helper(i, j-1, s, dp));
        }
        dp[i][j] = answer;
        return dp[i][j];
    }
    public boolean isValidPalindrome(String s, int k) {
        // Tricky because k will introduce three total variables
        int n = s.length();
        int[][] dp = new int[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = -1;
            }
        }
        int lps = helper(0, n-1, s, dp);
        return ((n-lps)<=k);
    }
}
