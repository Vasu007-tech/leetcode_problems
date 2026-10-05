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

    int findHeight(TreeNode* node) {
    if (node == NULL)
        return 0;

    int left = findHeight(node->left);
    int right = findHeight(node->right);

    return 1 + max(left, right);
}
    void findMax(TreeNode* node,int &maxi)
{
    if (node == NULL)
        return;

    int lh = findHeight(node->left);
    int rh = findHeight(node->right);

    maxi = max(maxi, lh + rh);

    findMax(node->left,maxi);
    findMax(node->right,maxi);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        findMax(root,maxi);
        return maxi;
    }
};