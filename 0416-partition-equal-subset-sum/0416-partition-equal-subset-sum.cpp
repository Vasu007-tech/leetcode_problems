class Solution {
public:
    bool func(int ind,vector<int>&nums,int target,vector<vector<int>>&dp){
        if(target==0)return true;
        if(ind==0) return (target==nums[ind]);
        if(dp[ind][target]!=-1)return dp[ind][target];
       int notTake= func(ind-1,nums,target,dp);
       int take = false;
       if(target>nums[ind]){
        take =func(ind-1,nums,target-nums[ind],dp);
       }
       return dp[ind][target]= take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2 != 0) return false;
        vector<vector<int>> dp(n,vector<int>(sum,-1));
        return func(n-1,nums,sum/2,dp);
        
    }
};