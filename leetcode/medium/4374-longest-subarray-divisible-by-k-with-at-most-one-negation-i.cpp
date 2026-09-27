class Solution {
    using ll = long long;
public:
    int longestSubarray(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        vector<int> rem(k, 0);
        for (int i = 0; i < n; i++) {
            ll sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                rem[((2 * nums[j]) % k + k) % k] = 1;
                int x = ((sum % k) + k) % k;
                if (x == 0 || rem[x] != 0) ans = max(ans, j - i + 1);
            }
            fill(rem.begin(), rem.end(), 0);
        }
        return ans;
    }
};