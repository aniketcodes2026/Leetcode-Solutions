
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {

                int best = INT_MAX;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;
                    int groups = d;
                    int cnt = len / d;

                    for (int r = 0; r < groups; r++) {
                        for (int t = 0; t < cnt / 2; t++) {

                            int x = i + r + t * d;
                            int y = i + r + (cnt - 1 - t) * d;

                            if (s[x] != s[y]) {
                                changes++;
                            }
                        }
                    }

                    best = min(best, changes);
                }

                cost[i][i + len - 1] = best;
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));

        dp[0][0] = 0;

        for (int p = 1; p <= k; p++) {
            for (int i = 2 * p; i <= n; i++) {

                for (int j = 2 * (p - 1); j <= i - 2; j++) {

                    if (dp[j][p - 1] == INT_MAX) continue;

                    dp[i][p] = min(dp[i][p],
                                   dp[j][p - 1] + cost[j][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};
