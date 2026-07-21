class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cnt1 = 0;
        for (int i = 0; i < n; i++) if (s[i] == '1') cnt1++;
        int cnt = 0;
        vector<int> zero;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') cnt++;
            else {
                if (cnt != 0) zero.push_back(cnt);
                cnt = 0;
            }
        }
        if (cnt != 0) zero.push_back(cnt);
        int m = zero.size();
        if (m <= 1) return cnt1;
        int ans = zero[0] + zero[1];
        for (int i = 1; i < m - 1; i++) ans = max(zero[i] + zero[i + 1], ans);
        return ans + cnt1;
    }
};