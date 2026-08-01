class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int cnt = 0, left = 0, n = nums.size(), k_count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 0) k_count++;
            
            while (k_count > k) {
                if (nums[left] % 2 != 0) k_count--;
                left++;
            }
            
            cnt += i - left + 1;
        }
        return cnt;   // outside the loop now
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};