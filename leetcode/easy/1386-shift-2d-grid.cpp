class Solution {
    vector<vector<int>> func(vector<vector<int>>& grid, int i, int j) {
        while (i < j) {
            swap(grid[i / grid[0].size()][i % grid[0].size()], grid[j / grid[0].size()][j % grid[0].size()]);
            i++;
            j--;
        }
        return grid;
    }
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        k = k % (m * n);
        if (k == 0) return grid;
        func(grid, 0, n * m - 1);
        func(grid, 0, k - 1);
        func(grid, k, n * m - 1);
        return grid;
    }
};