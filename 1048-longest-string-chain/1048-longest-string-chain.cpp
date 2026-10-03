class Solution {
public:
bool compare(string &word1,string &word2){
    int i=0,j=0,cnt=0;
    if(word1.length()!=word2.length()+1) return false;
    while(i<word1.size() && j<word2.size()){
        if(word1[i]!=word2[j]){
            if(cnt==0){
                cnt++;
                i++;
            }
            else return false;
        }else{

                j++;
                i++;
        }
    }
    return true;
}
static bool comp(string &s1,string &s2){
    return s1.size()<s2.size();
}
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int maxi =1;
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i]= 1+dp[j];
                }
                maxi=max(maxi,dp[i]);
            }
        }
        return maxi;
    }
};