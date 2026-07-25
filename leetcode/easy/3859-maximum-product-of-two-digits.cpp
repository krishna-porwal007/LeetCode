class Solution {
public:
    int maxProduct(int n) {
        int mx = -1, smx = -1;
        while (n) {
            int ld = n % 10;
            if (ld > mx) {
                smx = mx;
                mx = ld;
            }
            else if (ld > smx) smx = ld;
            n /= 10;
        }
        cout << smx << " " << mx;
        return smx * mx;
    }
};