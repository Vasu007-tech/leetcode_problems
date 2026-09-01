class Solution {
public:
int func(int i,vector<int>&nums,vector<int>&dp){
    if(i==0) return nums[i];
    if(i<0)return 0;
    if(dp[i]!=-1) return dp[i];
    int pick = nums[i]+func(i-2,nums,dp);
    int notPick = func(i-1,nums,dp);
    return dp[i]=max(pick,notPick);
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return func(nums.size()-1,nums,dp);
        
    }
};