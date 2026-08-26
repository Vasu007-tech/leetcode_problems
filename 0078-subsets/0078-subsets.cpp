class Solution {
public:

    void func(vector<int>&nums,vector<int>&temp,vector<vector<int>>& ans,int i){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        func(nums,temp,ans,i+1);
        temp.push_back(nums[i]);
        func(nums,temp,ans,i+1);
        temp.pop_back();
        

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
         func(nums,temp,ans,0);
         return ans;
        
    }
};