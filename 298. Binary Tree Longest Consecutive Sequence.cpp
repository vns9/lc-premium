// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 1;
    int helper(TreeNode* node){
        int curr = 1;
        if(node->left){
            if((node->left->val) == ((node->val)+1)){
                curr = max(curr, 1+helper(node->left));
            }
            else helper(node->left);
        }
        if(node->right){
            if((node->right->val) == ((node->val)+1)){
                curr = max(curr, 1+helper(node->right));
            }
            else helper(node->right);
        }
        ans = max(ans, curr);
        return curr;
    }
    int longestConsecutive(TreeNode* root) {
        helper(root);
        return ans;
    }
};
