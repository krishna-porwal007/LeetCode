class Solution {
    using ll = long long;
public:
    vector<int> countTasks(vector<int>& t, vector<int>& s) {
        int n = t.size();
        int m = s.size();
        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + t[i];
        ll idx = 0, avl = 0;
        vector<int> ans(m, 0);
        for (int i = 0; i < m; i++) {
            long long t = pref[idx] + avl + s[i];
            auto it = lower_bound(pref.begin() + idx + 1, pref.end(), t);
            if (it == pref.end()) {
                ans[i] = 0;
                avl = 0;
                idx = 0;
            }
            else if (*it == t) {
                idx = it - pref.begin();
                avl = 0;
                if (idx != n) ans[i] = n - idx;
                else {
                    ans[i] = 0;
                    idx = 0;
                }
            }
            else {
                --it;
                idx = it - pref.begin();
                avl = t - *it;
                ans[i] = n - idx;
            }
        }
        return ans;
    }
};