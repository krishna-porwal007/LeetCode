class Solution {
public:
    int countRotations(string s, int k) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            rotate(s.begin(), s.begin() + 1, s.end());
            int x = 0;
            for (int j = 1; j < s.size(); j++) {
                if (s[j] == s[j - 1]) x++;
            }
            if (x == k) cnt++;
        }
        return cnt;
    }
};