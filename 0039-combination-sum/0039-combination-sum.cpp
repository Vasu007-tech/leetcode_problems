class Solution {
public:

    void func(vector<vector<int>> &ans , vector<int>&temp,vector<int>&candidates,int k,int i,int sum){
        if(i==candidates.size() || sum>k){
            if(sum==k){
                ans.push_back(temp);
            }
            return;
        }

        func(ans,temp,candidates,k,i+1,sum);
        temp.push_back(candidates[i]);
        sum+=candidates[i];
        func(ans,temp,candidates,k,i,sum);
        sum-=candidates[i];
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> >ans;
        vector<int>temp;
        func(ans,temp,candidates,target,0,0);
        return ans;
    }
};