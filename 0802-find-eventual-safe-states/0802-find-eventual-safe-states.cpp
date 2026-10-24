class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<vector<int>> adjRev(n);
        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(auto &p:adj[i]){
                adjRev[p].push_back(i);
                indegree[i]++;
            }
        }
    queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int> safeNode;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNode.push_back(node);
            for(auto &p:adjRev[node]){
                indegree[p]--;
                if(indegree[p]==0)q.push(p);
            }
        }
        sort(safeNode.begin(),safeNode.end());
        return safeNode;
    }
};