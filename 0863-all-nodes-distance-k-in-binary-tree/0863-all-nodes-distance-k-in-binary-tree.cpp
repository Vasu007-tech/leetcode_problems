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
    void markParents(TreeNode* root ,unordered_map<TreeNode*,TreeNode*> &parent_track){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* parent = q.front();
            q.pop();
            if(parent->left){
                parent_track[parent->left]=parent;
                q.push(parent->left);
            }
            if(parent->right){
                parent_track[parent->right]=parent;
                q.push(parent->right);
            }
        }

    }

    vector<int> func(TreeNode* root, TreeNode* target, int k){
        queue<TreeNode*>q;
        unordered_map<TreeNode*,TreeNode*> parent_track;
        markParents(root,parent_track);
        unordered_map<TreeNode*,bool> visited;
        q.push(target);
        visited[target]=true;
        int curr=0;
        while(!q.empty()){
            int size=q.size();
            if(curr==k)break;
            curr++;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent_track[node] && !visited[parent_track[node]]){
                    q.push(parent_track[node]);
                    visited[parent_track[node]]=true;
                }

            }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        return func(root,  target,  k);
    }
};