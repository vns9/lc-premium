// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        vector<Node*> v1;
        vector<Node*> v2;
        Node* curr = p;
        while(curr!=nullptr){
            v1.push_back(curr);
            curr = curr->parent;
        }
        curr = q;
        while(curr!=nullptr){
            v2.push_back(curr);
            curr = curr->parent;
        }
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        Node* ans = nullptr;
        for(int i=0;i<min(v1.size(),v2.size());i++){
            if(v1[i]==v2[i]) ans = v1[i];
            else break;
        }
        return ans;
    }
};
