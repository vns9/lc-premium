// https://leetcode.com/problems/number-of-distinct-binary-strings-after-applying-operations/description/

class Solution {
public:
    int countDistinctStrings(string s, int k) {
        int n = s.size();
        int curr = 1;
        for(int i=k;i<=n;i++){
            curr*=2;
            curr%=1000000007;
        }
        return curr;
    }
};
