class Solution {
public:
    int func(int i,vector<int>&coins , int amount,vector<vector<int>> &dp){
        if(i==0){
            if(amount %coins[i]==0)return amount/coins[i];
            return 1e9;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        int notPick = func(i-1,coins,amount,dp);
        int pick = INT_MAX;
        if(amount>=coins[i]){
            pick = 1+func(i,coins,amount-coins[i],dp);
        }
        return dp[i][amount]=min(pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n =coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1 ,-1));
             int ans=func(n-1,coins,amount,dp);  
             if(ans==1e9) return -1;
             else return ans; 
    }
};