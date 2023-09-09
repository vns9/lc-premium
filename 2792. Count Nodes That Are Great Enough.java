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
    // we need the k minimum value nodes
    // int is by copy and Integer is by reference - what a weird language
    // just use &
    // weirdo - no one returns a fricking priority queue
    PriorityQueue<Integer> helper(TreeNode node, int[] gnc, int k){
        // take that, C++
        PriorityQueue<Integer> tmp = new PriorityQueue<Integer>((a, b) -> (b - a));
        if(node==null) return tmp;
        PriorityQueue<Integer> lpq = helper(node.left, gnc, k);
        PriorityQueue<Integer> rpq = helper(node.right, gnc, k);
        for(int el: lpq){
            tmp.add(el);
        }
        for(int el: rpq){
            tmp.add(el);
        }
        tmp.add(node.val);
        while(tmp.size() > k){
            tmp.poll();
        }
        if(tmp.size()==k && node.val>tmp.peek()){
            gnc[0]++;
        }
        return tmp;
    }
    public int countGreatEnoughNodes(TreeNode root, int k) {
        int[] gnc = new int[1];
        gnc[0] = 0;
        helper(root, gnc, k);
        return gnc[0];
    }
}
