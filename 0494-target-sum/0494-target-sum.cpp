class Solution {
public:
    int func(int i, int target, vector<int>& nums,
             vector<vector<int>>& dp) {

        // Base case
        if(i == 0) {
            if(nums[0] == 0 && target == 0)
                return 2;

            if(target == nums[0] || target == 0)
                return 1;

            return 0;
        }

        if(dp[i][target] != -1)
            return dp[i][target];

        // Don't take nums[i]
        int notPick = func(i - 1, target, nums, dp);

        // Take nums[i]
        int pick = 0;
        if(target >= nums[i]) {
            pick = func(i - 1, target - nums[i], nums, dp);
        }

        return dp[i][target] = pick + notPick;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int sum = 0;
        for(int x : nums)
            sum += x;

        // Impossible if target is outside [-sum, sum]
        if(abs(target) > sum)
            return 0;

        // S1 = (sum + target) / 2
        if((sum + target) % 2 != 0)
            return 0;

        int subsetTarget = (sum + target) / 2;

        vector<vector<int>> dp(
            n,
            vector<int>(subsetTarget + 1, -1)
        );

        return func(n - 1, subsetTarget, nums, dp);
    }
};