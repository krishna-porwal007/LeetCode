class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        // dp[idx][buy/sell][remaining transaction]
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 1; k <= 2; k++) {
                    if (j == 0) {
                        int pick = - p[i] + dp[i + 1][1][k];
                        int np = 0 + dp[i + 1][0][k];
                        dp[i][0][k] = max(pick, np);
                    }
                    else {
                        int pick = p[i] + dp[i + 1][0][k - 1];
                        int np = 0 + dp[i + 1][1][k];
                        dp[i][1][k] = max(pick, np);
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};