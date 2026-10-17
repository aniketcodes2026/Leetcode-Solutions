class Solution {
public:
    int ds(int x) {
        int s = 0;
        while (x)
            s += x % 10, x /= 10;
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> a = nums, pos(n);

        sort(a.begin(), a.end(), [&](int x, int y) {
            if (ds(x) != ds(y))
                return ds(x) < ds(y);
            return x < y;
        });

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]] = i;

        for (int i = 0; i < n; i++) {
            if (nums[i] == a[i])
                continue;

            int j = mp[a[i]];
            mp[nums[i]] = j;
            mp[a[i]] = i;
            swap(nums[i], nums[j]);
            ans++;
        }

        return ans;
    }
};