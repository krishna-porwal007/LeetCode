class Solution {
    void dfs(int n, int m, vector<vector<int>> &cp, int r, int c, int src, int col) {
        if (r >= n || c >= m || c < 0 || r < 0)
            return;
        if (cp[r][c] != src)
            return;
        cp[r][c] = col;
        dfs(n, m, cp, r + 1, c, src, col);
        dfs(n, m, cp, r, c + 1, src, col);
        dfs(n, m, cp, r - 1, c, src, col);
        dfs(n, m, cp, r, c - 1, src, col);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int src = image[sr][sc];
        if (src == color) return image;
        vector<vector<int>> cp = image;
        dfs(n, m, cp, sr, sc, src, color);
        return cp;
    }
};