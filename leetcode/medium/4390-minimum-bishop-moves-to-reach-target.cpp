class Solution {
public:
    int minBishopMoves(vector<int>& sr, vector<int>& t) {
        if ((sr[0] + sr[1]) % 2 != (t[0] + t[1]) % 2) return -1;
        if (sr[0] == t[0] && sr[1] == t[1]) return 0;
        if (abs(sr[0] - t[0]) == abs(sr[1] - t[1])) return 1;
        return 2;
    }
};