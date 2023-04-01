// https://leetcode.com/problems/paint-fence/description/

class Solution {
public:
    int helper(int n, int k, int flag){
        if(n==1){
            if(flag==1) return k;
            else return 0;
        }
        if(n==2){
            if(flag==2) return k;
            else return k*(k-1);
        }
        if(flag==2){
            int tmp = 0;
            int prev = helper(n-2,k,1);
            tmp += prev*(k-1);
            prev = helper(n-2,k,2);
            tmp += prev*(k-1);
            return tmp;
        }
        int tmp = 0;
        int prev = helper(n-2,k,1);
        tmp += prev*k*(k-1);
        prev = helper(n-2,k,2);
        tmp += prev*(k-1)*(k-1);
        return tmp;

    }
    int numWays(int n, int k) {
        return helper(n,k,1)+helper(n,k,2);
    }
};
