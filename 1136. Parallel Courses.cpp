// https://leetcode.com/problems/parallel-courses/description/

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        map<int,int> precnt;
        for(int i=1;i<=n;i++) precnt[i];
        map<int, vector<int>> adj;
        for(auto relation: relations){
            adj[relation[0]].push_back(relation[1]);
            precnt[relation[1]]++;
        }
        queue<int> q;
        for(auto kv: precnt){
            if(kv.second==0) q.push(kv.first);
        }
        int semcnt = 0;
        vector<int> vis(n,0);
        while(!q.empty()){
            semcnt++;
            int qsize = q.size();
            for(int i=0;i<qsize;i++){
                int qtop = q.front();
                vis[qtop-1] = 1;
                q.pop();
                for(auto neib: adj[qtop]){
                    if(precnt[neib]==0) continue;
                    precnt[neib]--;
                    if(precnt[neib]==0) q.push(neib);
                }
            }         
        }
        int ccnt = 0;
        for(auto el: vis){
            if(el>0) ccnt++;
        }
        if(ccnt==n) return semcnt;
        return -1;
    }
};
