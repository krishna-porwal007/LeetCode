class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        int n = word.size();
        for (int i = 0; i < n; i++) freq[word[i] - 'a']++;
        sort(freq.begin(), freq.end());
        int ans = 0;
        for (int i = 25; i >= 0 && freq[i]; i--) ans += freq[i] * ((25 - i) / 8 + 1);
        return ans;
    }
};