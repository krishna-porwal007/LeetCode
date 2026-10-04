class Solution {
public:
    bool checkValidString(string s) {
        int cnt = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '*') cnt++;
            else cnt--;
            if (cnt < 0) return false;
        }
        cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*') cnt++;
            else cnt--;
            if (cnt < 0) return false;
        }
        return true;
    }
};