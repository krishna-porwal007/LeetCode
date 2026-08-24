class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + stones[i];
        vector<int> dp(n + 2, 0);
        dp[n] = pref[n];
        for (int i = n - 1; i >= 2; i--) {
            int take = pref[i] - dp[i + 1];
            int notake = dp[i + 1];
            dp[i] = max(take, notake);
        } 
        return dp[2];
    }
};