class Solution {
public:
    int maxPalindromes(string s, int len) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n - i + 1; j++) {
                int k = j + i - 1;
                if (i <= 2) dp[j][k] = (s[j] == s[k]);
                else dp[j][k] = (s[j] == s[k] && dp[j + 1][k - 1]);
            }
        }
        vector<int> pochaMon(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            pochaMon[i] = pochaMon[i + 1];
            for (int j = i; j < n; j++) {
                if (j - i + 1 >= len && dp[i][j] == 1) pochaMon[i] = max(pochaMon[i], 1 + pochaMon[j + 1]);
            }
        }
        return pochaMon[0];
    }
};