class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = n + 1, sum = 0, i = 0;
        vector<int> dp(n + 1, n);
        for (int j = 0; j < n; j++) {
            sum += arr[j];
            while (sum > k) {
                sum -= arr[i];
                i++;
            }
            dp[j + 1] = dp[j];
            if (sum == k) {
                ans = min(ans, j - i + 1 + dp[i]);
                dp[j + 1] = min(dp[j], j - i + 1);
            }
        }
        return ans == n + 1 ? -1 : ans;
    }
};