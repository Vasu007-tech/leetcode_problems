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
    int func(TreeNode* p,TreeNode*q){
        if(p==NULL && q == NULL) return 1;
        if(p==NULL|| q==NULL)return -1;
        if(p->val != q->val) return -1;
       int right = func(p->right,q->left);
       if(right==-1)return -1;
       int left = func(p->left,q->right);
       if(left ==-1)return-1;
       return 1;
    }
    bool isSymmetric(TreeNode* root) {
        if(func(root->left,root->right)==1)return true;
        return false;
        
    }
};