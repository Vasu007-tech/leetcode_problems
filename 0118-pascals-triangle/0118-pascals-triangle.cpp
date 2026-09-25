class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        ans[0].resize(1);
        ans[0][0]=1;
        for(int i=1;i<n;i++){
            ans[i].resize(i+1);
            for(int j=0;j<i+1;j++){
                if(j-1<0) ans[i][j]=ans[i-1][j];
                else if(j==i) ans[i][j]=ans[i-1][j-1];
                else ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
            }
        }
        return ans;
    }
};