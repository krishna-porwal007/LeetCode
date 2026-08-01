class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + nums[i];
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = nums[i];
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j + i - 1 < n; j++) {
                int end = i + j - 1;
                int sum = pref[end + 1] - pref[j];
                dp[j][end] = sum - min(dp[j + 1][end], dp[j][end - 1]);
            }
        }
        return 2 * dp[0][n - 1] >= pref[n];
    }
};