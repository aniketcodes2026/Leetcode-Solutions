class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& a, int target, int start, vector<int>& v) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }

        for (int i = start; i < a.size(); i++) {
            if (i > start && a[i] == a[i - 1]) continue;
            if (a[i] > target) break;

            v.push_back(a[i]);
            solve(a, target - a[i], i + 1, v);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> v;
        solve(candidates, target, 0, v);
        return ans;
    }
};