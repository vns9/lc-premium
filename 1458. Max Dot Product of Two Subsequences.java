class Solution {
    int helper(int p1, int p2, int[] nums1, int[] nums2, int[][] dp1, int[][] dp2, boolean flag){
        if(!flag){
            if(p1==-1 || p2==-1) return 0;
            if(dp2[p1][p2]!=Integer.MIN_VALUE) return dp2[p1][p2];
            dp2[p1][p2] = 0;
            int answer = helper(p1-1, p2, nums1, nums2, dp1, dp2, flag);
            answer = Math.max(answer, helper(p1, p2-1, nums1, nums2, dp1, dp2, flag));
            answer = Math.max(answer, Math.max(0, nums1[p1]*nums2[p2])+helper(p1-1, p2-1, nums1, nums2, dp1, dp2, flag));
            dp2[p1][p2] = answer;
            return dp2[p1][p2];
        }
        if(p1==-1 || p2==-1) return Integer.MIN_VALUE;
        if(dp1[p1][p2] != Integer.MIN_VALUE) return dp1[p1][p2];
        int answer = helper(p1-1, p2, nums1, nums2, dp1, dp2, flag); 
        answer = Math.max(answer, helper(p1, p2-1, nums1, nums2, dp1, dp2, flag));
        answer = Math.max(answer, nums1[p1]*nums2[p2]+helper(p1-1, p2-1, nums1, nums2, dp1, dp2, !flag));
        dp1[p1][p2] = answer;
        return dp1[p1][p2];
    }
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        int[][] dp1 = new int[n1][n2];
        int[][] dp2 = new int[n1][n2];
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                dp1[i][j] = Integer.MIN_VALUE;
                dp2[i][j] = Integer.MIN_VALUE;
            }
        }
        return helper(n1-1, n2-1, nums1, nums2, dp1, dp2, true);
    }
}
