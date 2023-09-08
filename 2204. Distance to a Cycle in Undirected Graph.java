class Solution {
    void dfs(int node, int dis, int[] noncyc, int[] mindis, ArrayList<ArrayList<Integer>> adj){
        mindis[node] = dis;
        noncyc[node] = 2;
        for(int i=0; i<adj.get(node).size(); i++){
            int currentNeib = adj.get(node).get(i);
            if(noncyc[currentNeib]==1){
                noncyc[currentNeib] = 2;
                dfs(currentNeib, dis+1, noncyc, mindis, adj);
            }
        }
    }
    public int[] distanceToCycle(int n, int[][] edges) {
        int[] neighbourCnt = new int[n];
        int[] noncyc = new int[n];
        int[] mindis = new int[n];
        Queue<Integer> q = new LinkedList<>(); 
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i=0; i<n; i++){
            neighbourCnt[i] = 0;
            noncyc[i] = 0;
            mindis[i] = 0;
        }
        for(int i=0; i<n; i++){
            ArrayList<Integer> tmp = new ArrayList<>();
            adj.add(tmp);
        }
        for(int i=0; i<edges.length; i++){
            neighbourCnt[edges[i][0]]++;
            neighbourCnt[edges[i][1]]++;
            adj.get(edges[i][0]).add(edges[i][1]);
            adj.get(edges[i][1]).add(edges[i][0]);
        }
        for(int i=0; i<n; i++){
            if(neighbourCnt[i] == 1){
                q.add(i);
            }
        }
        while(!q.isEmpty()){
            int qtop = q.poll();
            noncyc[qtop] = 1;
            neighbourCnt[qtop] = 0;
            for(int j=0; j<adj.get(qtop).size(); j++){
                if(neighbourCnt[adj.get(qtop).get(j)]==0){
                    continue;
                }
                if(neighbourCnt[adj.get(qtop).get(j)]==1){
                    noncyc[adj.get(qtop).get(j)] = 1;
                    neighbourCnt[adj.get(qtop).get(j)] = 0;
                }
                if(neighbourCnt[adj.get(qtop).get(j)]>1){
                    neighbourCnt[adj.get(qtop).get(j)]--;
                }
                if(neighbourCnt[adj.get(qtop).get(j)] ==  1){
                    noncyc[qtop] = 1;
                    q.add(adj.get(qtop).get(j));
                }
            }
        }
        for(int i = 0; i<n; i++){
            if(noncyc[i] == 0){
                dfs(i, 0, noncyc, mindis, adj);
            }
        }
        return mindis;
    }
}