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
    void findVal(TreeNode* root,int &value,TreeNode* &ans){
        if(root==nullptr) return;
        if(root->val==value){
            ans=root;
            return;
        }
        if(value<root->val) findVal(root->left,value,ans);
        if(value>root->val) findVal(root->right,value,ans);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans=nullptr;
        findVal(root,val,ans);
        return ans;
    }
};
