class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =0,mini=prices[0],n=prices.size();
        for(int i=1;i<n;i++){
            int cost = prices[i]-mini;
            profit=max(cost,profit);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};