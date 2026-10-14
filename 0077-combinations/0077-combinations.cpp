
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;

        function<void(int)> solve = [&](int start) {
            if (curr.size() == k) {
                ans.push_back(curr);
                return;
            }

            for (int i = start; i <= n; i++) {
                curr.push_back(i);
                solve(i + 1);
                curr.pop_back();
            }
        };

        solve(1);
        return ans;
    }
};
