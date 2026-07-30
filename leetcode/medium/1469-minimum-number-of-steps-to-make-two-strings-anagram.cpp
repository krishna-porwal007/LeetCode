class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freqs(26, 0), freqt(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            freqs[s[i] - 'a']++;
            freqt[t[i] - 'a']++;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) if (freqs[i] - freqt[i] > 0) cnt += (freqs[i] - freqt[i]);
        return cnt;
    }
};