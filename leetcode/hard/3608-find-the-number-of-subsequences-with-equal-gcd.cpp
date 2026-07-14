class Solution {
    const int MOD = 1e9 + 7;
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (mx + 1, vector<int> (mx + 1, 0)));
        dp[0][0][0] = 1;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int g1 = 0; g1 <= mx; g1++) {
                for (int g2 = 0; g2 <= mx; g2++) {
                    long long cur = dp[i][g1][g2];
                    if (!cur) continue;
                    dp[i + 1][g1][g2] = (dp[i + 1][g1][g2] + cur) % MOD;
                    int x = (g1 == 0 ? num : __gcd(g1, num));
                    dp[i + 1][x][g2] = (dp[i + 1][x][g2] + cur) % MOD;
                    int y = (g2 == 0 ? num : __gcd(g2, num));
                    dp[i + 1][g1][y] = (dp[i + 1][g1][y] + cur) % MOD;
                }
            }
        }
        long long ans = 0;
        for (int i = 1; i <= mx; i++) ans = (ans + dp[n][i][i]) % MOD;
        return ans;
    }
};