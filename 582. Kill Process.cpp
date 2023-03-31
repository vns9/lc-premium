// https://leetcode.com/problems/kill-process/description/

class Solution {
public:
    vector<int> ans;
    void helper(int ps, map<int,vector<int>>& mp){
        if(mp.find(ps)==mp.end()) return;
        for(auto neib: mp[ps]){
            ans.push_back(neib);
            helper(neib, mp);
        }
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = ppid.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[ppid[i]].push_back(pid[i]);
        }
        ans={kill};
        helper(kill, mp);
        return ans;
    }
};
