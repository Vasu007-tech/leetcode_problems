class Solution {
public:
    int func(string& s,string &t,int i,int j,vector<vector<int>>&dp){
        if(i<=0||j<=0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==t[j-1]) return dp[i][j]= 1+func(s,t,i-1,j-1,dp);
        else return dp[i][j]= max(func(s,t,i-1,j,dp),func(s,t,i,j-1,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t=s;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        reverse(t.begin(),t.end());
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=n;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
       return dp[n][n];
    }
};