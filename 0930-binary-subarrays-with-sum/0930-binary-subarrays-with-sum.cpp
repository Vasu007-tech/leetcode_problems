class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int sum=0;
        int left=0;
        int cnt=0;
       for(int i=0;i<n;i++){
        sum+=nums[i];
        while(sum>goal && left<=i){
            sum-=nums[left];
            left++;
        }
        
            cnt+=i-left+1;
       }
        
        int sum1=0;
        int left1=0;
        int cnt1=0;
        if(goal<0) cnt1=0;
        else{

       for(int i=0;i<n;i++){
        sum1+=nums[i];
        while(sum1>goal-1 && left1<=i){
            sum1-=nums[left1];
            left1++;
        }
     
            cnt1+=i-left1+1;
       }
        }
        return cnt-cnt1;
    }
};
