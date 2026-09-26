class Solution {
public:
int func(int i,int j ,string &s , string &r,vector<vector<int>> &dp){
    if(i<0||j<0)return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==r[j]){
        return dp[i][j]= 1+func(i-1,j-1,s,r,dp);
    }
    return dp[i][j]= max(func(i-1,j,s,r,dp),func(i,j-1,s,r,dp));
}
    int longestPalindromeSubseq(string s) {
        string r =s;
        int n = s.size();
        int i=0,j=n-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;j--;
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return func(n-1,n-1,s,r,dp);

    }
};