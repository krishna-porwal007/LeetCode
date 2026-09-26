class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string, string> mp;
        for (auto v : k) mp[v[0]] = v[1];
        int n = s.size(), i = 0;
        string ans = "";
        while (i < n) {
            char b = s[i];
            if (b == '(') {
                string temp = "";
                while (s[i] != ')' && i < n) {
                    if (s[i] != '(') temp += s[i];
                    i++;
                }
                cout << temp << "\n";
                auto it = mp.find(temp);
                string ad = (it != mp.end()) ? it -> second : "?";
                ans += ad;
                i++;
                continue;
            }
            ans += b;
            i++;
        }
        return ans;
    }
};