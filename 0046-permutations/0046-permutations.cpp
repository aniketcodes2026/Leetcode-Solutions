class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        function<void(vector<int>&, int)> solve = [&](vector<int>& a, int i) {
            if (i == a.size()) {
                ans.push_back(a);
                return;
            }

            for (int j = i; j < a.size(); j++) {
                swap(a[i], a[j]);
                solve(a, i + 1);
                swap(a[i], a[j]); // backtrack
            }
        };

        solve(nums, 0);
        return ans;
    }
};