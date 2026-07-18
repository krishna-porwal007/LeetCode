class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        map<char, int> mp;
        int n = s.size();
        for (int i = 0; i < n; i++) mp[s[i]]++;
        string t = "";
        t += string(mp[y], y);
        t += string(mp[x], x);
        for (auto it : mp) {
            if (it.first == y) continue;
            else if (it.first == x) continue;
            else t += string(it.second, it.first);
        }
        return t;
    }
};