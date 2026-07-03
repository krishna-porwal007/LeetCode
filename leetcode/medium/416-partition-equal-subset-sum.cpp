class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0ll);
        if (sum % 2) return false;
        sum /= 2;
        vector<vector<bool>> dp(n + 1, vector<bool> (sum + 1, false));
        for (int i = 0; i <= n; i++) dp[i][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int s = 1; s <= sum; s++) {
                int np = dp[i - 1][s];
                int p = 0;
                if (s - nums[i - 1] >= 0) p = dp[i - 1][s - nums[i - 1]];
                dp[i][s] = p | np;
            }
        }
        return dp[n][sum];
    }
};