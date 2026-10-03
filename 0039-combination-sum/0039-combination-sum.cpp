class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& c, int target, int i, vector<int>& v) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }

        if (i == c.size() || target < 0) return;

        if (c[i] <= target) {
            v.push_back(c[i]);
            solve(c, target - c[i], i, v);
            v.pop_back();
        }

        solve(c, target, i + 1, v);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        solve(candidates, target, 0, v);
        return ans;
    }
};