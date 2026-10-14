
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        function<void(int)> solve = [&](int i) {
            if (i == nums.size()) {
                ans.push_back(curr);
                return;
            }

            curr.push_back(nums[i]);
            solve(i + 1);

            curr.pop_back();
            solve(i + 1);
        };

        solve(0);
        return ans;
    }
};
