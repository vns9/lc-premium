// https://leetcode.com/problems/binary-tree-vertical-order-traversal/description/

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
    int cnt = 0;
    map<int,vector<vector<int>>> mp;
    void helper(TreeNode* node, int col, int height){
        if(node==nullptr) return;
        mp[col].push_back({height,cnt,node->val});
        cnt++;
        helper(node->left, col-1, height+1);
        helper(node->right, col+1, height+1);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        helper(root,0,0);
        vector<vector<int>> ans;
        for(auto kv: mp){
            sort(kv.second.begin(),kv.second.end());
            vector<int> tmp;
            for(auto el: kv.second) tmp.push_back(el[2]);
            ans.push_back(tmp);
        }
        return ans;
    }
};
