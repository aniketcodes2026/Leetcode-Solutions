class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(2, -2)));

        function<int(int,int,int)> solve = [&](int x, int y, int d) -> int {
            if (x >= m || y >= n) return -1;

            if (grid[x][y] == 0) return x * n + y;

            if (memo[x][y][d] != -2) return memo[x][y][d];

            if (d == 0)
                return memo[x][y][d] = solve(x + 1, y, 1);
            else
                return memo[x][y][d] = solve(x, y + 1, 0);
        };

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == 0) continue;

                if (i == m - 1 && j == n - 1) continue;

                if (j + 1 < n) {
                    int p = solve(i, j + 1, 0);
                    if (p != -1) {
                        dp[p / n][p % n] = (dp[p / n][p % n] + dp[i][j]) % MOD;
                    }
                }

                if (i + 1 < m) {
                    int p = solve(i + 1, j, 1);
                    if (p != -1) {
                        dp[p / n][p % n] = (dp[p / n][p % n] + dp[i][j]) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};