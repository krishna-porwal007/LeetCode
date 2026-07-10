class Solution {
public:
    int coinChange(vector<int>& c, int a) {
        int n = c.size();
        vector<int> dp(a + 1, 1e9);
        dp[0] = 0;
        for (int i = 0; i < n; i++) for (int sum = 1; sum < a + 1; sum++) if (sum >= c[i]) dp[sum] = min(dp[sum], dp[sum - c[i]] + 1);
        return (dp[a] == 1e9 ? -1 : dp[a]);
    }
};