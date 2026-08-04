class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp (n + 1, vector<int> (2, 0));
        dp[n][0] = 0;
        dp[n][1] = 0;
        // 0 -> buy 1 -> sell
        // if buy then take not take, similarly for sell
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                if (j == 0) {
                    int pick = -p[i] + dp[i + 1][1];
                    int np = 0 + dp[i + 1][0];
                    dp[i][0] = max(pick, np);
                }
                else {
                    int pick = p[i] + dp[i + 1][0];
                    int np = 0 + dp[i + 1][1];
                    dp[i][1] = max(pick, np);
                } 
            }
        } 
        return dp[0][0];
    }
};