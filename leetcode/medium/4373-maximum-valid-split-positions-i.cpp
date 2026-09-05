class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = -1; i < n; i++) {
            vector<int> a;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                a.push_back(nums[j]);
            }
            int m = a.size();
            if (m <= 1) continue;
            vector<int> pref(m), suff(m);
            pref[0] = a[0], suff[m - 1] = a[m - 1];
            for (int j = 1; j < m; j++) pref[j] = __gcd(pref[j - 1], a[j]);
            for (int j = m - 2; j >= 0; j--) suff[j] = __gcd(suff[j + 1], a[j]);
            int cnt = 0;
            for (int k = 0; k < m - 1; k++) if (pref[k] == suff[k + 1]) cnt++;
            ans = max(cnt, ans);
        }
        return ans;
    }
};