class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& in, int l, int r) {
        sort(in.begin(), in.end());
        vector<vector<int>> res;
        res.push_back(in[0]);
        for (int i = 1; i < in.size(); i++) {
            if (in[i][0] <= res.back()[1] + 1)
                res.back()[1] = max(res.back()[1], in[i][1]);
            else res.push_back(in[i]);
        }
        vector<vector<int>> ans;
        for (auto it : res) {
            if (it[1] < l || it[0] > r) ans.push_back(it);
            else {
                if (l > it[0]) ans.push_back({it[0], l - 1});
                if (r < it[1]) ans.push_back({r + 1, it[1]});
            }
        }
        return ans;
    }
};