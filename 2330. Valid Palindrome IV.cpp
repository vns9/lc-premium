// https://leetcode.com/problems/valid-palindrome-iv/description/

class Solution {
public:
    bool makePalindrome(string s) {
        int diff = 0;
        int n = s.size();
        int p1 = 0;
        int p2 = n-1;
        while(p1<=p2){
            if(s[p1]!=s[p2]){
                diff++;
            }
            p1++;
            p2--;
        }   
        if(diff<=2) return true;
        return false;
    }
};
