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
        for(int i=0;i<m;i++){
            dp[m-1][i]=triangle[m-1][i];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                 int d=triangle[i][j]+dp[i+1][j];
        int dg = triangle[i][j]+dp[i+1][j+1];
      dp[i][j]=min(d,dg);
            }
        }
        return dp[0][0];
    }
};