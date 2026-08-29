class Solution {
public:
    void func(int k, int n, int start,
              vector<int>& ds,
              vector<vector<int>>& ans) {

        if (k == 0) {
            if (n == 0)
                ans.push_back(ds);
            return;
        }

        for (int i = start; i <= 9; i++) {

            if (i > n)
                break;

            ds.push_back(i);

            func(k - 1, n - i, i + 1, ds, ans);

            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;

        func(k, n, 1, ds, ans);

        return ans;
    }
};