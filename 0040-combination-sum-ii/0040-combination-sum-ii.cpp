class Solution {
public:

    void func(vector<int>&arr,int target,int ind,vector<int> &ds,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target)break;
            ds.push_back(arr[i]);
            func(arr,target-arr[i],i+1,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        func(candidates,target,0,ds,ans);
        return ans;
    }
};