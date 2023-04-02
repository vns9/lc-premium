// https://leetcode.com/problems/minimum-number-of-keypresses/description/

class Solution {
public:
    int minimumKeypresses(string s) {
        int ones = 9;
        int twos = 9;
        int threes = 8;
        vector<int> v1;    
        for(int i=0;i<8;i++) v1.push_back(3);
        for(int i=0;i<9;i++) v1.push_back(2);
        for(int i=0;i<9;i++) v1.push_back(1);
        vector<int> v(26);
        for(auto c: s){
            v[c-'a']++;
        }
        sort(v.begin(),v.end());
        int ans = 0;
        for(int i=0;i<26;i++){
            ans += v[i]*v1[i];
        }
        return ans;
    }
};
