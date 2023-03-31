// https://leetcode.com/problems/merge-operations-to-turn-array-into-a-palindrome/description/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int p1 = 0;
        int p2 = n-1;
        while(p1<=p2){
            if(nums[p1]==nums[p2]){
                p1++;
                p2--;
            }
            else if(nums[p1]<nums[p2]){
                nums[p2]-=nums[p1];
                nums[p1]=0;
                ans++;
                nums[p1+1]+=nums[p1];
                p1++;
            }
            else{
                nums[p1]-=nums[p2];
                nums[p2]=0;
                ans++;
                nums[p2-1]+=nums[p2];
                p2--;
            }
        }
        return ans;
    }
};
