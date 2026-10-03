class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
          int n = nums.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
       vector<int> dp(n,1),hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
        int maxi=0;
        for(int i =0;i <n;i++){
            for(int prev_ind=0;prev_ind<i;prev_ind++){
                if(nums[i]%nums[prev_ind]==0){
                    if(dp[i]<1+dp[prev_ind]){
                        dp[i]= 1+dp[prev_ind];
                        hash[i]=prev_ind;
                    }
                }
            }
                if(dp[maxi]<dp[i]) maxi =i;
        }
        while(maxi!=hash[maxi]){
           ans.push_back(nums[maxi]);
            maxi = hash[maxi];
        }
           ans.push_back(nums[maxi]);
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};