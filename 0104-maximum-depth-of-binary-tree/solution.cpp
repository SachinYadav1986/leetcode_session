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
    int maxx(TreeNode* curr){
        if(curr==nullptr) return 0;
        int left=maxx(curr->left);
        int right= maxx(curr->right);
        return 1+max(left,right);
    }
    int maxDepth(TreeNode* root) {
        return maxx(root);
    }
};
