class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < n1 || j < n2) {
            int x;
            if (i == n1) x = s2[j][0];
            else if (j == n2) x = s1[i][0];
            else x = min(s2[j][0], s1[i][0]);
            int y1 = 0, y2 = 0;
            if (i < n1) y1 = s1[i][1];
            if (j < n2) y2 = s2[j][1];
            ans.push_back({x, y1 + y2});
            if (i < n1 && s1[i][0] == x) i++;
            if (j < n2 && s2[j][0] == x) j++;
        }
        return ans;
    }
};