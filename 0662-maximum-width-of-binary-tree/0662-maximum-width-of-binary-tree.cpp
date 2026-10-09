
class Solution {
public:
    int func(TreeNode* root) {
        if (root == NULL) return 0;

        map<int, vector<long long>> mpp;
        queue<pair<TreeNode*, pair<long long, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            int sz = q.size();
            long long base = q.front().second.first;

            for (int i = 0; i < sz; i++) {
                auto p = q.front();
                q.pop();

                TreeNode* node = p.first;
                long long x = p.second.first - base;
                int y = p.second.second;

                mpp[y].push_back(x);

                if (node->left) {
                    q.push({node->left, {2 * x + 1, y + 1}});
                }

                if (node->right) {
                    q.push({node->right, {2 * x + 2, y + 1}});
                }
            }
        }

        int maxi = 0;

        for (auto p : mpp) {
            long long mini = *min_element(
                p.second.begin(), p.second.end()
            );
            long long maxu = *max_element(
                p.second.begin(), p.second.end()
            );

            maxi = max(maxi, (int)(maxu - mini + 1));
        }

        return maxi;
    }

    int widthOfBinaryTree(TreeNode* root) {
        return func(root);
    }
};
