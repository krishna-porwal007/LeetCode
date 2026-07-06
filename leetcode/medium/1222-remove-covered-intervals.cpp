class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        sort(in.begin(), in.end(), cmp);
        int ans = 0;
        int r = -1;
        for (auto it : in) {
            if (it[1] > r) {
                ans++;
                r = it[1];
            }
        }
        return ans;
    }
};