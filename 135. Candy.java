class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int[] dp = new int[n];
        int[] indeg = new int[n];
        HashMap<Integer, ArrayList<Integer>> mp = new HashMap<>();
        for(int i=0; i<(n-1); i++){
            if(ratings[i] < ratings[i+1]){
                if(!mp.containsKey(i)){
                    ArrayList<Integer> el = new ArrayList<>();
                    mp.put(i, el);
                }
                mp.get(i).add(i+1);
                indeg[i+1]++;
            }
            if(ratings[i+1] < ratings[i]){
                if(!mp.containsKey(i+1)){
                    ArrayList<Integer> el = new ArrayList<>();
                    mp.put(i+1, el);
                }
                mp.get(i+1).add(i);
                indeg[i]++;
            }
        }
        Queue<Integer> bfs = new LinkedList<>();
        for(int i=0; i<n; i++){
            if(indeg[i] == 0){
                bfs.add(i);
            }
        }
        int currdis = 1;
        while(!bfs.isEmpty()){
            int qsize = bfs.size();
            for(int i=0; i<qsize; i++){
                int qtop = bfs.poll();
                dp[qtop] = currdis;
                if(mp.containsKey(qtop)){
                    for(Integer neib: mp.get(qtop)){
                        indeg[neib]--;
                        if(indeg[neib]==0){
                            bfs.add(neib);
                        }
                    }
                }
            }
            currdis++;
        }
        int answer = 0;
        for(int each: dp){
            answer += each;
        }
        return answer;
    }   
}
