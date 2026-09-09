class Solution {
    using ll = long long;
    // 1e15 = 1,000,000,000,000,000
public:
    long long countCommas(long long n) {
        ll arr[] = {999ll, 999999ll, 999999999ll, 999999999999ll, 999999999999999ll};
        ll ans = 0;
        for (auto it : arr) ans += max(0ll, n - it);
        return ans;
    }
};