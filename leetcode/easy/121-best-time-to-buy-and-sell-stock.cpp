class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<int> p(n), s(n);
        p[0] = a[0], s[n - 1] = a[n - 1];
        for (int i = 1; i < n; i++) p[i] = min(p[i - 1], a[i]);
        for (int i = n - 2; i >= 0; i--) s[i] = max(s[i + 1], a[i]);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] >= p[i]) ans = max(ans, s[i] - p[i]);
        }
        return ans;
    }
};