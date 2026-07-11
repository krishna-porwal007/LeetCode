class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            queue<int> q;
            q.push(i);
            vis[i] = true;
            int v = 0, e = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                v++;
                e += adj[u].size();
                for (int node : adj[u]) {
                    if (!vis[node]) {
                        vis[node] = true;
                        q.push(node);
                    }
                }
            }
            e /= 2;
            if (e == (v * (v - 1)) / 2) ans++;
        }
        return ans;
    }
};