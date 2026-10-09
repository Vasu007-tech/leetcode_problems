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
    vector<int> func(TreeNode* root){
        if(root==NULL)return {};
        map<int,int> mpp;
        queue<pair<TreeNode*,int>> q;
        int y=0;
        q.push({root,y});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            y=p.second;
            if(mpp.find(y)==mpp.end())
            mpp[y]=node->val;
            if(node->right){
                q.push({node->right,y+1});
            }
            if( node->left){
                q.push({node->left,y+1});
            }
        }
        vector<int> ans;
        for(auto p:mpp){
            ans.push_back(p.second);
        }
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        return func(root);
    }
};