class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int t) {
        int n = nums.size();
        vector<int> dp(t + 1, -1e9);
        dp[0] = 0;
        for (int i = 0; i < n; i++) for (int sum = t; sum >= 1; sum--) if (sum >= nums[i]) dp[sum] = max(dp[sum], dp[sum - nums[i]] + 1);
        return (dp[t] < 0 ? -1 : dp[t]);
    }
};