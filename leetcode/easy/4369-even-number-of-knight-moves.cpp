class Solution {
    const int n = 8;
    int func(int sr, int sc, int tr, int tc) {
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int dr[] = {-2,-2,-1,-1,1,1,2,2};
        int dc[] = {-1,1,-2,2,-2,2,-1,1}; 
        q.push({{sr, sc}, 0});
        vis[sr][sc] = 1;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int s = q.front().second;
            q.pop();
            if (r == tr && c == tc) return s;
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 & nr < n && nc >= 0 && nc < 8 && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, s + 1});
                }
            }
        }
        return -1;
    }
public:
    bool canReach(vector<int>& s, vector<int>& t) {
        if (func(s[0], s[1], t[0], t[1]) % 2) return false;
        return true; 
    }
};