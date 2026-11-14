class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        multiset<int> st;
        int ans = INT_MAX;

        for (int i = l; i <= n; i++) {
            st.insert(pref[i - l]);

            if (i - r - 1 >= 0) {
                st.erase(st.find(pref[i - r - 1]));
            }

            auto it = st.upper_bound(pref[i] - 1);

            if (it != st.begin()) {
                --it;
                int sum = pref[i] - *it;

                if (sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};