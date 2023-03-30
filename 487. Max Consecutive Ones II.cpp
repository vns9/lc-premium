// https://leetcode.com/problems/max-consecutive-ones-ii/description/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        bool flip = false;
        int p1 = 0;
        int p2 = 0;
        int n = nums.size();
        while(p2<n){
            if(nums[p2]==1){
                ans = max(ans, p2-p1+1);
                p2++;
            }
            else{
                if(!flip){
                    ans = max(ans, p2-p1+1);
                    flip = true;
                    p2++;
                }
                else{
                    while(p1<p2){
                        if(nums[p1]==0){
                            p1++;
                            break;
                        } 
                        else p1++;
                    }
                    ans = max(ans, p2-p1+1);
                    p2++;
                }
            }
        }
        return ans;
    }
};
