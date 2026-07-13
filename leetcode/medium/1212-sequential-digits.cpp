class Solution {
    vector<int> a;
public:
    vector<int> sequentialDigits(int low, int high) {
        for(int len = 2; len <= 9; len++) {
            int f = 0, s = 0;
            for (int d = 1; d <= len; d++) {
                f = f * 10 + d;
                s = s * 10 + 1;
            }
            int cur = f;
            for (int i = 0; i < 10 - len; i++) {
                if (cur >= low && cur <= high) a.push_back(cur);
                cur += s;
            }
        }
        return a;
    }
};