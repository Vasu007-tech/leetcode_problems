class Solution {
public:

    vector<int> convertBinary(int val) {
        vector<int> res;

        if (val == 0) {
            res.push_back(0);
            return res;
        }

        while (val > 0) {
            res.push_back(val % 2);
            val = val / 2;
        }

        reverse(res.begin(), res.end());

        return res;
    }

    int minBitFlips(int start, int goal) {

        vector<int> startB = convertBinary(start);
        vector<int> goalB = convertBinary(goal);

        int n = startB.size();
        int m = goalB.size();

        // Make both binary vectors equal in size
        if (n < m) {
            startB.insert(startB.begin(), m - n, 0);
        }
        else if (m < n) {
            goalB.insert(goalB.begin(), n - m, 0);
        }

        int cnt = 0;

        for (int i = 0; i < startB.size(); i++) {
            if (startB[i] != goalB[i]) {
                cnt++;
            }
        }

        return cnt;
    }
};