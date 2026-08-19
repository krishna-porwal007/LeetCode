class Solution {
    /*
        expected TC isn't O(n * 10)
        so you can't put more than 2 in one row
        let's sort(reserved)
    */
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        sort(r.begin(), r.end());
        int ans = 0, i = 0;
        while (i < r.size()) {
            int row = r[i][0];
            bool a = true, b = true, c = true;
            while (i < r.size() && r[i][0] == row) {
                if (r[i][1] >= 2 && r[i][1] <= 5) a = false;
                if (r[i][1] >= 4 && r[i][1] <= 7) b = false;
                if (r[i][1] >= 6 && r[i][1] <= 9) c = false;
                i++;
            }
            if (a && c) ans += 2;
            else if (a || b || c) ans++;
            else ans += 0;
        }
        int reserve = 0;
        i = 0;
        while (i < r.size()) {
            reserve++;
            int row = r[i][0];
            while (i < r.size() && r[i][0] == row) i++;
        }
        ans += 2 * (n - reserve);
        return ans;
    }
};