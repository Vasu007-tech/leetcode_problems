class Solution {
public:
    int func(int n,vector<int>&dp){
        if(dp[n]!=-1) return dp[n];
        if(n==0) return 1;
        if(n==1) return 1;
       dp[n-1] =  func(n-1,dp);
        dp[n-2] =func(n-2,dp);
        return dp[n-1]+dp[n-2];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
           return func(n,dp);
    }
};