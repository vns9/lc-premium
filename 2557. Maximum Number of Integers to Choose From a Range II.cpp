// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-ii/description/

class Solution {
public:
    int maxCount(vector<int>& banned, int n, long long maxSum) {
        sort(banned.begin(),banned.end());
        while(!banned.empty() && banned.back()>n){
            banned.pop_back();
        }
        vector<int> tmp;
        for(auto el: banned){
            if(tmp.empty() || tmp.back()<el){
                tmp.push_back(el);
            }
        }
        banned.clear();
        for(auto el: tmp){
            banned.push_back(el);
        }
        int ban_n = banned.size();
        vector<long long int> pre;
        for(auto el: banned) pre.push_back(el);
        for(int i=1;i<ban_n;i++){
            pre[i] += pre[i-1];
        }
        long long int lo = 1;
        long long int hi = n;
        int ans = 0;
        while(lo<=hi){
            long long int mid = lo+(hi-lo)/2;
            int banidx = -1;
            int banlo = 0;
            int banhi = ban_n-1;
            while(banlo<=banhi){
                int banmid = banlo + (banhi-banlo)/2;
                if(banned[banmid]>mid){
                    banhi = banmid-1;
                }
                else{
                    banidx = banmid;
                    banlo = banmid+1;
                }
            }
            long long int sum = (mid*(mid+1)/2);
            if(banidx!=-1) sum -= pre[banidx];
            if(sum<=maxSum){
                ans = mid;
                if(banidx!=-1){
                    ans -= (banidx+1);
                }
                
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return ans;
    }
};
