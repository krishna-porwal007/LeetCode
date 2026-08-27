class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);
        int n = s.size();
        for (char c : s) cnt[c - 'a']++;
        for (int i = n - 1; i >= 0; i--) {
            vector<int> remain = cnt;
            bool poss = true;
            for (int j = 0; j < i; j++) {
                if (remain[target[j] - 'a'] == 0) {
                    poss = false;
                    break;
                }
                remain[target[j] - 'a']--;
            }
            if (!poss) continue;
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (remain[c] == 0) continue;
                string ans = target.substr(0, i);
                ans += char('a' + c);
                remain[c]--;
                for (int i = 0; i < 26; i++) ans.append(remain[i], char(i + 'a'));
                return ans;
            }
        }
        return "";
    }
};