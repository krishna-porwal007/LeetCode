class Solution {
    bool func(string &s, string &t) {
        int n = s.size();
        if (n != t.size()) return false;
        int diff = 0;
        for (int i = 0; i < n && diff < 2; i++) diff += (s[i] != t[i]);
        return diff == 1;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1), hash(n);
        for (int i = 0; i < n; i++) hash[i] = i;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (groups[i] != groups[prev] && func(words[i], words[prev]) && 1 + dp[prev] > dp[i]) {
                    dp[i] = (1 + dp[prev]);
                    hash[i] = prev;
                }
            }
        }
        int index = max_element(dp.begin(), dp.end()) - dp.begin();
        vector<string> ans;
        while (hash[index] != index) {
            ans.push_back(words[index]);
            index = hash[index];
        }
        ans.push_back(words[index]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};