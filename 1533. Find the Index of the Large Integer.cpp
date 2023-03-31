// https://leetcode.com/problems/find-the-index-of-the-large-integer/description/

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int n = reader.length();
        int lo = 0;
        int hi = n-1;
        while(lo<=hi){
            int mid = lo +(hi-lo)/2;
            int api = -2;
            if((hi-lo+1)%2==0){
                api = reader.compareSub(lo,mid,mid+1,hi);
                if(api==1){
                    hi = mid;
                }
                else{
                    lo = mid+1;
                }
            }
            else{
                api = reader.compareSub(lo,mid,mid,hi);
                if(api==0){
                    return mid;
                }
                else if(api==1){
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
        }
        return 0;
    }
};
