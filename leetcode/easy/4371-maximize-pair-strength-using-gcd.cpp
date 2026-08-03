class Solution {
    using ll = long long;
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        __int128 mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ll g = __gcd(nums[i], nums[j]);
                __int128 val = (__int128)nums[i] * nums[j];
                val = val / ((__int128)g * g);
                mx = max(mx, val);
            }
        }
        return mx;
    }
};