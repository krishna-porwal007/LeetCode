class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int t) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((t + sum) % 2 == 1) return 0;
        if (abs(t) > sum) return 0;
        t += sum;
        t /= 2;
        if (t < 0) return 0;
        vector<int> dp(t + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) for (int sum = t; sum >= nums[i]; sum--) dp[sum] += dp[sum - nums[i]];
        return dp[t];
    }
};