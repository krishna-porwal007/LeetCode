class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (k + 1, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (j == 0) dp[i][j][cap] = max(-p[i] + dp[i + 1][1][cap], dp[i + 1][0][cap]);
                    else dp[i][j][cap] = max(p[i] + dp[i + 1][0][cap - 1], dp[i + 1][1][cap]);
                }
            }
        }
        return dp[0][0][k];
    }
};