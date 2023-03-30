// https://leetcode.com/problems/meeting-scheduler/description/

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(),slots1.end());
        sort(slots2.begin(),slots2.end());
        int n1 = slots1.size();
        int n2 = slots2.size();
        int p1 = 0, p2 = 0;
        while(p1<n1 && p2<n2){
            if(slots1[p1][1]<=slots2[p2][0]) p1++;
            else if(slots2[p2][1]<=slots1[p1][0]) p2++;
            else{
                int intersection = min(slots1[p1][1],slots2[p2][1])-max(slots1[p1][0],slots2[p2][0]);
                if(intersection>=duration){
                    return {max(slots1[p1][0],slots2[p2][0]), max(slots1[p1][0],slots2[p2][0])+duration};
                }
                else{
                    if(slots2[p2][1]>slots1[p1][1]){
                        p1++;
                    }
                    else p2++;
                }
            }
        }
        return {};
    }
};
