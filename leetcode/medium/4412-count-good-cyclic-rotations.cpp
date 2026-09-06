class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + nums[i - 1];
        long long sum = pref[n], ans = 0;
        for (int i = 0; i < n; i++) {
            long long first;
            if (i + n / 2 <= n) first = pref[i + n / 2] - pref[i];
            else first = (pref[n] - pref[i]) + pref[i + n / 2 - n];
            if (2 * first > sum) ans++;
        }
        return ans;
    }
};