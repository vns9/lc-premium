// https://leetcode.com/problems/minimum-adjacent-swaps-to-make-a-valid-array/description/

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int min_el = *min_element(nums.begin(),nums.end());
        int max_el = *max_element(nums.begin(),nums.end());
        int minidx = -1;
        int maxidx = -1;
        for(int i=0;i<n;i++){
            if(nums[i]==min_el){
                minidx = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]==max_el){
                maxidx = i;
                break;
            }
        }
        if(minidx==maxidx) return 0;
        if(maxidx>minidx) return minidx+(n-1-maxidx);
        return minidx+(n-1-maxidx)-1;
    }
};
