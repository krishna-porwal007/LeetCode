class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n = a.size();
        int m = a[0].size();
        int l = 0, r = n - 1, row = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid][0] == target) {
                return true;
            }
            else if (a[mid][0] < target) {
                l = mid + 1;
                row = mid;
            }
            else {
                r = mid - 1;
            }
        }
        if (row == -1) return false;
        l = 0, r = m - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[row][mid] == target) return true;
            else if (a[row][mid] < target) {
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return false;
    }
};