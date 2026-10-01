class Solution {
public:
    int func(int i,int buy,int cap,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(i== prices.size()) return 0;
        if(cap==0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        int profit =0;
        if(buy){
            profit = max(-prices[i]+func(i+1,0,cap,prices,dp),func(i+1,1,cap,prices,dp));
        }
        else profit = max(prices[i]+func(i+1,1,cap-1,prices,dp),func(i+1,0,cap,prices,dp));
        return dp[i][buy][cap]=profit;

    }
    int maxProfit(int k,vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return func(0,1,k,prices,dp);        
    }
};