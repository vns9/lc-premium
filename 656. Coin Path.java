class Solution {
    public List<Integer> cheapestJump(int[] coins, int maxJump) {
        ArrayList<Integer> answer = new ArrayList<>();
        HashMap<Integer, ArrayList<Integer>> firstIndex = new HashMap<>();
        int n = coins.length;
        if(coins[n-1] == -1) return answer;
        int[] dp = new int[n];
        dp[n-1] = coins[n-1];
        for(int i=n-2; i>=0; i--){
            dp[i] = Integer.MAX_VALUE;
        }
        ArrayList<Integer> tmp = new ArrayList<>();
        tmp.add(n-1);
        firstIndex.put(coins[n-1], tmp);
        for(int i=n-2; i>=0; i--){
            if(coins[i]==-1) continue;
            for(int j=(i+1); j<=Math.min(n-1, i+maxJump); j++){
                if(coins[j]==-1) continue;
                dp[i] = Math.min(dp[i], coins[i]+dp[j]);
            }
            if(!firstIndex.containsKey(dp[i])){
                firstIndex.put(dp[i], new ArrayList<Integer>());
            }
            firstIndex.get(dp[i]).add(i);
        }
        for(int i=0; i<n; i++){
            System.out.println(dp[i]+" ");
        }
        for(Integer key: firstIndex.keySet()){
            Collections.reverse(firstIndex.get(key));
        }
        if(dp[0] == Integer.MAX_VALUE) return answer;
        int current = 0;
        answer.add(1);
        int currentSum = dp[0]-coins[0];
        while(current!=(n-1)){
            int lo = 0;
            int hi = 0;
            try{
                hi = firstIndex.get(currentSum).size()-1;
            }
            catch(Exception e){
                return Collections.EMPTY_LIST;
            }
            int id = -1;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                if((firstIndex.get(currentSum).get(mid) - current) > maxJump){
                    hi = mid-1;
                }
                else if((firstIndex.get(currentSum).get(mid) - current) <= 0){
                    lo = mid+1;
                }
                else{
                    id = firstIndex.get(currentSum).get(mid);
                    hi = mid-1;
                }
            }
            if(id==-1){
                return Collections.EMPTY_LIST;
            }
            answer.add(id+1);
            current = id;
            currentSum -= coins[id];
        }
        return answer;
    }
}
