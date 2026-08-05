class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nr = r + dx[k];
                            int nc = c + dy[k];
                            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && !vis[nr][nc]) {
                                vis[nr][nc] = 1;
                                q.push({nr, nc});
                            }
                        }
                    }
                } 
            }
        }
        return cnt;
    }
};