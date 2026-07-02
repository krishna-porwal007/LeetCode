class Solution {
    int n, m;
    vector<vector<int>> a;
    bool func (int i, int j, int h, vector<vector<vector<int>>> &dp, vector<vector<vector<bool>>> &vis) {
        if (i == n - 1 && j == m - 1) return true;
        if (dp[i][j][h] != -1) return dp[i][j][h];
        if (vis[i][j][h]) return false;
        vis[i][j][h] = true;
        int dx[] = {0, 1, 0, -1}; 
        int dy[] = {1, 0, -1, 0};
        for (int d = 0; d < 4; d++) {
            int newi = i + dx[d], newj = j + dy[d];
            if (newi < 0 || newj < 0 || newi >= n || newj >= m) continue;
            int newh = h - a[newi][newj];
            if (newh <= 0) continue;
            if (func(newi, newj, newh, dp, vis)) {
                vis[i][j][h] = false;
                return dp[i][j][h] = 1;
            }
        }
        vis[i][j][h] = false;
        return dp[i][j][h] = 0;
    }
public:
    bool findSafeWalk(vector<vector<int>>& g, int h) {
       // since cycles exist, we can't use 2d dp
       // state i j health
       // can i reach i, j with h health currently
        a = g;
        n = g.size();
        m = g[0].size();
        h -= a[0][0];
        if (h <= 0) return false;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(h + 1, -1)));
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(h + 1, false)));
        return func(0, 0, h, dp, vis);
    }
};