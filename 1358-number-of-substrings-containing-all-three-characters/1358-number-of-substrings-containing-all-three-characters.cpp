class Solution {
public:
    int atMost(string s,int goal){
        unordered_map<char,int>mpp;//value->freq
        int cnt=0,left=0;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
            while(mpp.size()>goal){
                mpp[s[left]]--;
                if(mpp[s[left]]==0)mpp.erase(s[left]);
                left++;

            }
            if(mpp.size()<=goal){
                cnt+=i-left+1;
            }
        }
        return cnt;
    }
    int numberOfSubstrings(string s) {
        return atMost(s,3)-atMost(s,2);
        
    }
};