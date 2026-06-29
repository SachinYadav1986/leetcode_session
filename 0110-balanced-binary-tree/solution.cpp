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
    int maxx(TreeNode* curr,bool &temp){
        if(temp==false) return 0;
        if(curr==nullptr) return 0;
        int left=1+maxx(curr->left,temp);
        if(!temp) return 0;
        int right= 1+maxx(curr->right,temp);
        if(!temp) return 0;
        if(abs(left-right)>1){
            temp=false;
            return 0;
        }
        return max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        bool temp=true;
        maxx(root,temp);
        return temp;
    }
};
