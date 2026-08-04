class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size();
        vector<vector<int>> dp (n + 1, vector<int> (2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                if (j == 0) {
                    int pick = -p[i] + dp[i + 1][1];
                    int np = 0 + dp[i + 1][0];
                    dp[i][0] = max(pick, np);
                }
                else {
                    int pick = p[i] + dp[i + 1][0] - fee;
                    int np = 0 + dp[i + 1][1];
                    dp[i][1] = max(pick, np);
                }
            }
        } 
        return dp[0][0];
    }
};