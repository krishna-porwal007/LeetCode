class Solution {
public:
    string smallestPalindrome(string s) {
        map<int, int> mp;
        int n = s.size();
        for (int i = 0; i < n; i++) mp[s[i] - 'a']++;
        string ans = "", temp;
        char mid = 0;
        for (auto it : mp) {
            char c = it.first + 'a';
            if (it.second % 2) mid = c;
            it.second /= 2;
            while (it.second--) ans += c;
        }
        temp = ans;
        reverse(temp.begin(), temp.end());
        if (mid != 0) ans += mid;
        ans += temp;
        return ans;
    }
};