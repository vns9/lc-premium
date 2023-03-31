// https://leetcode.com/problems/leftmost-column-with-at-least-a-one/description/

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int rows = dim[0];
        int cols = dim[1];
        int x = 0;
        int y = cols-1;
        int ans = -1;
        while(x<rows && y>=0){
            if(binaryMatrix.get(x,y)==1){
                ans = y;
                y--;
            }
            else{
                x++;
            }
        } 
        return ans;   
    }
};
