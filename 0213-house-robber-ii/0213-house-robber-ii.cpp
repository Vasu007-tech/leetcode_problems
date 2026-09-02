class Solution {
public:
    int func(int i,vector<int>&nums,vector<int>&dp){
        if(i==0)return nums[i];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int pick = nums[i]+func(i-2,nums,dp);
        int notPick = func(i-1,nums,dp);
        return dp[i]= max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        vector<int>dp(nums.size(),-1);
        vector<int>dp1(nums.size(),-1);
        if(nums.size()==1)return nums[0];
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }
            return max(func(temp1.size()-1,temp1,dp),func(temp2.size()-1,temp2,dp1));
        
    }
};