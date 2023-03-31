// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int numDistChars = 0;
        map<char,int> cnt;
        int n = s.size();
        int p1 = 0;
        int p2 = 0;
        int ans = 0;
        while(p2<n){
            char curr = s[p2];
            if(cnt.find(curr)==cnt.end()||cnt[curr]==0){
                numDistChars++;
            }
            cnt[curr]++;
            while(numDistChars>k){
                char prev = s[p1];
                cnt[prev]--;
                if(cnt[prev]==0){
                    numDistChars--;
                }
                p1++;
            }
            ans = max(ans, p2-p1+1);
            p2++;
        }
        return ans;
    }
};
