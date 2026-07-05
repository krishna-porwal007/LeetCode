class Solution {
    const int MOD = 1e9 + 7;
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<int>> dp1 (n, vector<int> (n, INT_MIN)); // score
        vector<vector<int>> dp2 (n, vector<int> (n, 0)); // number of ways
        dp1[0][0] = 0;
        dp2[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (board[i][j] == 'X') continue;
                int best = INT_MIN;
                if (i) best = max(best, dp1[i-1][j]);
                if (j) best = max(best, dp1[i][j-1]);
                if (i && j) best = max(best, dp1[i-1][j-1]);
                if (best == INT_MIN) continue;
                int x = 0;
                if (board[i][j] >= '0' && board[i][j] <= '9') x = board[i][j] - '0';
                dp1[i][j] = best + x;
            }
        }
        if (dp1[n - 1][n - 1] == INT_MIN) return {0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (board[i][j] == 'X') continue;
                if (dp1[i][j] == INT_MIN) continue;
                int x = 0;
                if (board[i][j] >= '0' && board[i][j] <= '9') x = board[i][j] - '0';
                if (i && dp1[i - 1][j] != INT_MIN && dp1[i - 1][j] + x == dp1[i][j]) dp2[i][j] = ((dp2[i][j] + dp2[i - 1][j]) % MOD);
                if (j && dp1[i][j - 1] != INT_MIN && dp1[i][j - 1] + x == dp1[i][j]) dp2[i][j] = ((dp2[i][j] + dp2[i][j - 1]) % MOD);
                if (i && j && dp1[i - 1][j - 1] != INT_MIN && dp1[i - 1][j - 1] + x == dp1[i][j]) dp2[i][j] = ((dp2[i - 1][j - 1] + dp2[i][j]) % MOD);
            }
        }
        return {dp1[n - 1][n - 1], dp2[n - 1][n - 1]};
    }   
};