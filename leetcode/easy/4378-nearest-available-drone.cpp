class Solution {
public:
    int nearestDrone(vector<vector<int>>& d, vector<int>& t) {
        int n = d.size(), ans = INT_MAX, s = INT_MAX;
        for (int i = 0; i < n; i++) {
            int x = d[i][0], y = d[i][1], r = d[i][2];
            int currs = abs(t[0] - x) + abs(t[1] - y);
            if (currs <= r && currs < s) {
                ans = i;
                s = min(s, currs);
            }
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};