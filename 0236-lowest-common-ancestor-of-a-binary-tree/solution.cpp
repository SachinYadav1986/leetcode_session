/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public: 
    TreeNode* findCommon(TreeNode* root, TreeNode* &p, TreeNode* &q){
        if(root==nullptr || root==p || root==q) return root;
        TreeNode* leftNode=findCommon(root->left,p,q);
        TreeNode* rightNode=findCommon(root->right,p,q);
        if(leftNode==nullptr) return rightNode;
        else if(rightNode==nullptr) return leftNode;
        else{
            return root;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findCommon(root,p,q);
    }
};
