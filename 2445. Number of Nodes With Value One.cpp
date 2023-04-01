// https://leetcode.com/problems/number-of-nodes-with-value-one/description/

class Solution {
public:
    int numberOfNodes(int n, vector<int>& queries) {
        map<int,int> mp;
        for(int i=1;i<=n;i++) mp[i];
        for(auto query: queries){
            mp[query]++;
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            int cnt = 0;
            int curr = i;
            while(curr>0){
                cnt+=mp[curr];
                curr/=2;
            }
            if(cnt%2==1) ans++;
        }
        return ans;
    }
};
