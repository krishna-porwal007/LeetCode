class Solution {
public:
    int largestInteger(int n, int s) {
        if (n * 9 < s) return -1;
        int l = s / 9;
        int rem = s % 9;
        int x = pow(10, l) - 1;
        x = (x * 10) + rem;
        x = x * pow(10, n - l - 1);
        return x;
    }
};