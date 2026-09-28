class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, n = s.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') cnt++;
            else if (s[i] == ')') cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};