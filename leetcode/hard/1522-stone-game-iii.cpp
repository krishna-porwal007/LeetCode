class Solution {
public:
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = nums[i] - dp[i + 1];
            if (i + 1 < n) dp[i] = max(dp[i], nums[i] + nums[i + 1] - dp[i + 2]);
            if (i + 2 < n) dp[i] = max(dp[i], nums[i] + nums[i + 1] + nums[i + 2] - dp[i + 3]); 
        }
        if (dp[0] == 0) return "Tie";
        else if (dp[0] > 0) return "Alice";
        return "Bob";
    }
};