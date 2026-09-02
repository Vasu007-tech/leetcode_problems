class Solution {
public:
    int func(int m , int n,int sum,vector<vector<int>>&dp){
        if(m==0 && n==0) return 1;
        if(dp[m][n]!=-1)return dp[m][n];
        for(int i=0;i<2;i++){
            if(i==0 && m>0)sum+=func(m-1,n,0,dp);
            else if(i==1 && n>0) sum+=func(m,n-1,0,dp);
        }
        return dp[m][n]=sum;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(m-1,n-1,0,dp);
    }
};