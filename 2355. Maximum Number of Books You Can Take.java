class Solution {
    public long maximumBooks(int[] books) {
        int n = books.length;
        int[] modified = new int[n];
        for(int i=0; i<n; i++){
            modified[i] = (books[i]-i);
        }
        int[] prev_smaller_id = new int[n];
        for(int i=0; i<n; i++){
            prev_smaller_id[i] = -1;
        }
        Stack<Integer> s = new Stack<>();
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && (modified[s.peek()] > modified[i])){
                prev_smaller_id[s.peek()] = i;
                s.pop();
            }
            s.push(i);
        }
        long[] dp = new long[n];
        for(int i=0; i<n; i++){
            dp[i] = 0;
        }
        dp[0] = books[0];
        for(int i=1; i<n; i++){
            int psid = prev_smaller_id[i];
            long curr = (long)(books[i])*(i-psid);
            if(psid > (i-books[i])){
                long rem = (((long)(i-psid-1)*(i-psid))/2);
                curr -= rem;
                if(psid >= 0){
                    curr += dp[psid];
                }
            }
            else{
                curr = (long)(books[i])*(books[i]+1)/2;
            }      
            dp[i] = curr;
        }
        long answer = 0;
        for(int i=0; i<n; i++){
            if(answer < dp[i]) answer = dp[i];
        }
        return answer;
    }
}
