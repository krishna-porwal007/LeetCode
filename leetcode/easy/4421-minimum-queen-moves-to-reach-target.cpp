class Solution {
public:
    int minQueenMoves(vector<int>& s, vector<int>& t) {
        if (t[0] - s[0] == 0 && t[1] - s[1] == 0) return 0;
        if (t[0] - s[0] == 0 || t[1] - s[1] == 0 || abs(t[0] - s[0]) == abs(t[1] - s[1])) return 1;
        return 2; 
    }
};