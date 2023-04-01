// https://leetcode.com/problems/connecting-cities-with-minimum-cost/description/

class Solution {
public:
    int getPar(int i, vector<int>& par){
        if(par[i]==i) return i;
        return getPar(par[i], par);
    }
    bool merge(int i, int j, vector<int>& par, vector<int>& cnt){
        int par_i = getPar(i, par);
        int par_j = getPar(j, par);
        if(par_i==par_j) return false;
        if(cnt[par_i]>cnt[par_j]){
            par[par_j] = par_i;
            cnt[par_i] += cnt[par_j];
        }
        else{
            par[par_i] = par_j;
            cnt[par_j] += cnt[par_i];
        }
        return true;
    }
    int minimumCost(int n, vector<vector<int>>& connections) {
        int mst = 0;
        vector<int> par(n,0);
        vector<int> cnt(n,0);
        for(int i=0;i<n;i++){
            par[i] = i;
            cnt[i] = 1;
        }
        vector<vector<int>> sortedCon;
        for(auto connection: connections){
            sortedCon.push_back({connection[2],connection[0]-1,connection[1]-1});
        }
        sort(sortedCon.begin(),sortedCon.end());
        for(auto conn: sortedCon){
            if(merge(conn[1],conn[2],par,cnt)){
                mst += conn[0];
            }
        }
        int parcnt = 0;
        for(int i=0;i<par.size();i++){
            if(par[i]==i){
                parcnt++;
            }
        }
        if(parcnt!=1) return -1;
        return mst;
    }
};
