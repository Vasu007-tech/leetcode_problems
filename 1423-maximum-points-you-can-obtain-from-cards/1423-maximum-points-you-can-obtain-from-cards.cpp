class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        if(k==n) return sum;
        int j=n-1;
        int i=k-1;
        int max =sum;
        while(i>=0){
            sum=sum-cardPoints[i]+cardPoints[j];
            if(sum>max){
                max=sum;
            }
            i--;
            j--;
        }
        return max;
        
    }
};