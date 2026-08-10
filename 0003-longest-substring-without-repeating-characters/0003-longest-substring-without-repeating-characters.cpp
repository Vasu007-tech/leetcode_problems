class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> mpp;
        int cnt = 0, sum = 0,left =0;

        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                mpp.emplace(s[0]);
                cnt++;
            } else if (mpp.find(s[i]) == mpp.end()) {
                cnt++;
                mpp.emplace( s[i]);
            } else {

                sum = max(sum, cnt);
                while (mpp.find(s[i]) != mpp.end()) {
                    mpp.erase(s[left]);
                    left++;
                    cnt--;
                }
                mpp.emplace(s[i]);
                cnt++;
            }
        }
        return max(sum, cnt);
    }
};