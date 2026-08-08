class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int need = target-nums[i];
            if(mpp.find(need)!=mpp.end()){
                result.push_back(mpp[need]);
                result.push_back(i);
            }
            mpp[nums[i]]=i;
        }

        return result;
        
    }
};