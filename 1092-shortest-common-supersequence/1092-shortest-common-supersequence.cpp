class Solution {
public:
    int func(int i,int j,string &str1, string &str2,vector<vector<int>>&dp){
        if(i<=0 || j<=0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(str1[i-1]==str2[j-1])return dp[i][j]= 1+func(i-1,j-1,str1,str2,dp);
        return dp[i][j]= max(func(i-1,j,str1,str2,dp),func(i,j-1,str1,str2,dp));
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n =str1.size();
        int m =str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        func(n,m,str1,str2,dp);
        string ans="";
        int len = n+m-dp[n][m];
        for(int i=0;i<len;i++){
            ans+="$";
        }
        int index=len-1;
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans[index]=str1[i-1];
                index--;i--;j--;
            }
            else if (dp[i-1][j]>=dp[i][j-1]) {
                ans[index]=str1[i-1];
                i--;
                index--;}
            else if (dp[i][j-1]>dp[i-1][j]){
                ans[index]=str2[j-1];
                j--;index--;
            } 
        }
        while(i>0){
            ans[index]=str1[i-1];
            index--;
            i--;
        }
        while(j>0){
            ans[index]=str2[j-1];
            index--;
            j--;
        }
        return ans;
        }
    
};