class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1) return s;
        if (n % 2 == 0) return 1ll * s + (n / 2) * 1ll * m - 1ll * (n / 2 - 1);
        else return 1ll * s + 1ll * (n / 2) * (m - 1) + 1; 
    }
};