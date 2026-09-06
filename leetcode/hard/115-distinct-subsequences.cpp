class Solution {
    using ll = long long;
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if (n < m) return 0;
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long> (m + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][m] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) dp[i][j] = dp[i + 1][j] + dp[i + 1][j + 1];
                else dp[i][j] = dp[i + 1][j];
            }
        }
        return dp[0][0];
    }
};