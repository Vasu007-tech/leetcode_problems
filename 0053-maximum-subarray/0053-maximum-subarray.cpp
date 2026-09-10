class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN, i = 0,cnt=0;
        while (i < nums.size()) {
            if (cnt < 0) {
                cnt = nums[i];
            }
           else cnt += nums[i];
            i++;
            sum=max(sum,cnt);
        }
        return sum;
    }
};