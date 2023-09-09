/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    // Java ugghhhh
    public class Pair{
        TreeNode t;
        boolean res;
        Pair(TreeNode t1, boolean b1){
            t = t1;
            res = b1;
        }
        Pair(Pair y){
            t = y.t;
            res = y.res;
        }
        // omfg what the 
        // we needed java records like 20 years before
        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;
            Pair key = (Pair) o;
            return t == key.t && res == key.res;
        }
        @Override
        public int hashCode() {
            int result = 17;
            result = 31 * result + t.hashCode();
            result = 31 * result + (res ? 1 : 0);
            return result;
        }
    }
    public int minimumFlips(TreeNode root, boolean result) {
        HashMap<Pair, Integer> dp = new HashMap<>();
        minimumFlip(root, result, dp);
        return minimumFlip(root, result, dp);
    }
    public int minimumFlip(TreeNode root, boolean result, HashMap<Pair, Integer> dp) {
        if(root == null){
            return Integer.MAX_VALUE;
        }
        Pair key = new Pair(root, result);
        if(dp.containsKey(key)){
            return dp.get(key);
        }
        if(root.left == null && root.right == null){
            int needed = 0;
            if(result) needed = 1;
            if(root.val != needed) return 1;
            else return 0;
        }
        int leftFalse =  minimumFlip(root.left, false, dp);
        int rightFalse = minimumFlip(root.right, false, dp);
        int leftTrue = minimumFlip(root.left, true, dp);
        int rightTrue = minimumFlip(root.right, true, dp);
        if(root.val == 2){
            int answer = Integer.MAX_VALUE;
            if(result){
                answer = Math.min(answer, leftFalse+rightTrue);
                answer = Math.min(answer, leftTrue+rightFalse);
                answer = Math.min(answer, leftTrue+rightTrue);
            }
            else answer = Math.min(answer, leftFalse+rightFalse);
            dp.put(key, answer);
            return answer;
        }
        else if(root.val == 3){
            int answer = Integer.MAX_VALUE;
            if(result){
                answer = Math.min(answer, leftTrue+rightTrue);
            }
            else{
                answer = Math.min(answer, leftTrue+rightFalse);
                answer = Math.min(answer, leftFalse+rightTrue);
                answer = Math.min(answer, leftFalse+rightFalse);
            }
            dp.put(key, answer);
            return answer;
        }
        else if(root.val == 4){
            int answer = Integer.MAX_VALUE;
            if(result){
                answer = Math.min(answer, leftTrue+rightFalse);
                answer = Math.min(answer, leftFalse+rightTrue);
            }
            else{
                answer = Math.min(answer, leftTrue+rightTrue);
                answer = Math.min(answer, leftFalse+rightFalse);
            }
            dp.put(key, answer);
            return answer;
        }
        else if(root.val == 5){
            int answer = Integer.MAX_VALUE;
            if(result){
                answer = Math.min(answer, leftFalse);
                answer = Math.min(answer, rightFalse);
            }
            else{
                answer = Math.min(answer, rightTrue);
                answer = Math.min(answer, leftTrue);
            }
            dp.put(key, answer);
            return answer;
        }
        return 1;
    }
}
