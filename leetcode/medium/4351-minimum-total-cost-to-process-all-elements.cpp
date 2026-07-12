class Solution {
    using ll = long long;
    const int MOD = 1e9 + 7;
    const ll INV2 = 500000004;
public:
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        int K = k;
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            if (k >= nums[i]) k -= nums[i];
            else {
                ll req = ((ll)nums[i] - k + K - 1) / K;
                cnt += req;
                k = k - nums[i] + req * K;
            }
        }
        ll ans = (cnt % MOD) * ((cnt + 1) % MOD) % MOD;
        ans = ans * INV2 % MOD;
        return ans;
    }
};