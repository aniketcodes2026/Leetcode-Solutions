class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k);
        vector<long long> dp(k);

        for (int num : nums) {
            vector<long long> next(k);

            int value = num % k;

            next[value]++;

            for (int r = 0; r < k; r++) {
                int newRemainder = (r * value) % k;
                next[newRemainder] += dp[r];
            }

            for (int r = 0; r < k; r++) {
                ans[r] += next[r];
            }

            dp = next;
        }

        return ans;
    }
};
