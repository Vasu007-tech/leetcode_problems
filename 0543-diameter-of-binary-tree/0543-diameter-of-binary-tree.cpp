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
    int func(TreeNode* root,int &maxi){
        if(root == NULL) return 0;
        int right = func(root->right,maxi);
        int left = func(root->left,maxi);
        maxi = max(right+left,maxi);
        return 1+max(right,left);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        func(root,maxi);
        return maxi;
    }
};