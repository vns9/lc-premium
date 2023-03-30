// https://leetcode.com/problems/buildings-with-an-ocean-view/description/
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans;
        int cmax = -1;
        for(int i=n-1;i>=0;i--){
            if(heights[i]>cmax){
                ans.push_back(i);
                cmax = max(cmax, heights[i]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
