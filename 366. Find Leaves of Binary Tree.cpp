// https://leetcode.com/problems/find-leaves-of-binary-tree/description/

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
    map<TreeNode*,TreeNode*> leftC;
    map<TreeNode*,TreeNode*> rightC;
    map<TreeNode*,TreeNode*> par;
    queue<TreeNode*> q;
    void helper(TreeNode* curr){
        if(curr==nullptr) return;
        leftC[curr] = curr->left;
        rightC[curr] = curr->right;
        if(curr->left) par[curr->left] = curr;
        if(curr->right) par[curr->right] = curr;
        if(curr->left==nullptr && curr->right==nullptr){
            q.push(curr);
        }
        helper(curr->right);
        helper(curr->left);
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        par[root] = nullptr;
        helper(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int qsize = q.size();
            vector<int> tmp;
            for(int i=0;i<qsize;i++){
                TreeNode* curr = q.front();
                TreeNode* currpar = par[curr];
                q.pop();
                tmp.push_back(curr->val);
                if(currpar){
                    if(leftC[currpar]==curr){ currpar->left = nullptr; leftC[currpar]=nullptr;}
                    if(rightC[currpar]==curr){ currpar->right = nullptr; rightC[currpar]=nullptr;}
                    if(currpar->left==nullptr && currpar->right==nullptr){
                        q.push(currpar);
                    }
                }     
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
