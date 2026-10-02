class Solution {
public:
    int func(int i,int prev_ind,vector<int> &nums,vector<vector<int>> &dp){
        if(i==nums.size()) return 0;
        if(dp[i][prev_ind+1]!=-1) return dp[i][prev_ind+1];
        int take;
        if(prev_ind==-1||nums[prev_ind]<nums[i]){
         take = 1+func(i+1,i,nums,dp);
        }
        int notTake = func(i+1,prev_ind,nums,dp);
        return dp[i][prev_ind+1]= max(notTake,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
         vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return func(0,-1,nums,dp);
    }
};