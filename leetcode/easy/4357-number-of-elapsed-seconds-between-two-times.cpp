class Solution {
public:
    int secondsBetweenTimes(string st, string et) {
        int e = (10 * (et[0] -'0') + (et[1] - '0')) * 3600 + (10 * (et[3] -'0') + (et[4] - '0')) * 60 + (10 * (et[6] -'0') + (et[7] - '0'));
        int s = (10 * (st[0] -'0') + (st[1] - '0')) * 3600 + (10 * (st[3] -'0') + (st[4] - '0')) * 60 + (10 * (st[6] -'0') + (st[7] - '0'));
        return e - s;
    }
};