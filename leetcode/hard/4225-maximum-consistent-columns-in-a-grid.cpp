class Solution {
    bool valid (int i, int j, vector<vector<int>> &grid, int lim) {
        int n = grid.size();
        for (int k = 0; k < n; k++) if (abs(grid[k][j] - grid[k][i]) > lim) return false;
        return true;
    }
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m + 1, 1);
        int ans = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (valid(j, i, grid, limit)) dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};