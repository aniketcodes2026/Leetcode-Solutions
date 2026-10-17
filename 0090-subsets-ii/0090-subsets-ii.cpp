class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;

        function<void(int)> solve = [&](int i) {
            ans.push_back(cur);

            for (int j = i; j < nums.size(); j++) {
                if (j > i && nums[j] == nums[j - 1])
                    continue;

                cur.push_back(nums[j]);
                solve(j + 1);
                cur.pop_back();
            }
        };

        solve(0);
        return ans;
    }
};