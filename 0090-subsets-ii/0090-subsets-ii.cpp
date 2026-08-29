class Solution {
public:

void func(int i,vector<int> &nums,set<vector<int>> &ans,vector<int>&ds){
    if(i==nums.size()){
        ans.insert(ds);
        return;
    }
    func(i+1,nums,ans,ds);
    ds.push_back(nums[i]);
    func(i+1,nums,ans,ds);
    ds.pop_back();
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        set<vector<int>> temp;
        sort(nums.begin(),nums.end());
        func(0,nums,temp,ds);
        for(auto x:temp){
            ans.push_back(x);
        }
        return ans;
    }
};