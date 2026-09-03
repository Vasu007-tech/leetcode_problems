class Solution {
public:
    int func(int i ,int j,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if(i==triangle.size()-1)return triangle[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int d=triangle[i][j]+func(i+1,j,triangle,dp);
        int dg = triangle[i][j]+func(i+1,j+1,triangle,dp);
        return dp[i][j]=min(d,dg);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,INT_MAX));
        return func(0,0,triangle,dp);
    }
};