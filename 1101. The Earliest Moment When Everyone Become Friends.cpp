// https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/description/

class Solution {
public:
    int getParent(int curr, vector<int>& v){
        if(v[curr]==curr) return curr;
        return getParent(v[curr],v);
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        int ngroups = n;
        vector<int> v(n);
        vector<int> d(n,1);
        for(int i=0;i<n;i++){
            v[i] = i;
        }
        sort(logs.begin(),logs.end());
        for(auto log: logs){
            int par1 = getParent(log[1], v);
            int par2 = getParent(log[2], v);
            if(par1==par2) continue;
            else ngroups--;
            int s1 = d[par1];
            int s2 = d[par2];
            if(s1>=s2){
                v[par2] = par1;
                d[par1] += d[par2];
            }
            else{
                v[par1] = par2;
                d[par2] += d[par1];
            }
            if(ngroups==1) return log[0];
        }
        return -1;
    }
};
