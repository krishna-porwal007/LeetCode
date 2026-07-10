class Solution {
public:
    int change(int a, vector<int>& c) {
        int n = c.size();
        vector<unsigned int> dp(a + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) for (int sum = c[i]; sum < a + 1; sum++) dp[sum] += dp[sum - c[i]];
        return dp[a];
    }
};