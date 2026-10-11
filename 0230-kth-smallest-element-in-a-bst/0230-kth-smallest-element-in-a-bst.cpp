class Solution {
public:
    int func(TreeNode* root, int k, int &cnt) {
        if (root == NULL) return -1;

        int ans = func(root->left, k, cnt);
        if (ans != -1) return ans;

        cnt++;
        if (cnt == k) return root->val;

        return func(root->right, k, cnt);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return func(root, k, cnt);
    }
};