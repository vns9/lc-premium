// https://leetcode.com/problems/make-the-prefix-sum-non-negative/description/

class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        long long int curr = 0;
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        for(int i=0;i<n;i++){
            curr += nums[i];
            pq.push(nums[i]);
            if(curr<0){
                curr-=pq.top();
                pq.pop();
                cnt++;
            }
        }
        return cnt;
    }
};
