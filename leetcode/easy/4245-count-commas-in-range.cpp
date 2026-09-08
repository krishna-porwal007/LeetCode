class Solution {
    // 1e5 = 100,000; [1000, 100000]
public:
    int countCommas(int n) {
        return n < 1000 ? 0 : n - 999;
    }
};