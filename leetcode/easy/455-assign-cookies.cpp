class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size(), i = 0, j = 0;
        sort(g.begin(), g.end()); sort(s.begin(), s.end());
        while (i < n && j < m) {
            if (s[j] >= g[i]) {
                j++;
                i++;
            }
            else {
                j++;
            }
     
        }
        return i;
    }
};