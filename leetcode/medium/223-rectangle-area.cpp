class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // I wanna do something stupid in this
        // Case 1 : no overlap, has 4 parts to this
        int a1 = (ax2 - ax1) * (ay2 - ay1);
        int a2 = (bx2 - bx1) * (by2 - by1);
        if (ax2 <= bx1 || ay1 >= by2 || bx2 <= ax1 || by1 >= ay2) {
            return a1 + a2;
        }
        // Case 2 : Cuboid jesa overlap, like in example 1; has 4 parts once again; 2 sides intersecting
        if (bx2 >= ax2 && bx1 >= ax1  && bx1 < ax2) {
            if (ay1 >= by1 && ay2 >= by2 && by2 > ay1) {
                int rem = (ax2 - bx1) * (by2 - ay1);
                return a1 + a2 - rem;
            }
            else if (by1 >= ay1 && by1 < ay2 && by2 >= ay2) {
                int rem = (ax2 - bx1) * (ay2 - by1);
                return a1 + a2 - rem;
            }
        }
        else if (bx1 <= ax1 && ax1 < bx2 && bx2 <= ax2) {
            if (by1 <= ay1 && ay1 < by2 && by2 <= ay2) {
                int rem = (bx2 - ax1) * (by2 - ay1);
                return a1 + a2 - rem;
            }
            else if (ay1 <= by1 && by1 < ay2 && ay2 <= by2) {
                int rem = (bx2 - ax1) * (ay2 - by1);
                return a1 + a2 - rem;
            }
        }
        // Case 3 : 3 lines intersecting 
        if (bx1 <= ax1 && ax2 <= bx2) {
            if (by1 <= ay1 && ay1 < by2 && by2 <= ay2) {
                int rem = (ax2 - ax1) * (by2 - ay1);
                return a1 + a2 - rem;
            }
            else if (ay1 <= by1 && by1 < ay2 && ay2 <= by2) {
                int rem = (ax2 - ax1) * (ay2 - by1);
                return a1 + a2 - rem;
            }
        }
        if (by1 <= ay1 && ay2 <= by2) {
            if (bx1 <= ax1 && ax1 < bx2 && bx2 <= ax2) {
                int rem = (bx2 - ax1) * (ay2 - ay1);
                return a1 + a2 - rem;
            }
            else if (ax1 <= bx1 && bx1 < ax2 && ax2 <= bx2) {
                int rem = (ax2 - bx1) * (ay2 - ay1);
                return a1 + a2 - rem;
            }
        }
        if (ax1 <= bx1 && bx2 <= ax2) {
            if (by1 <= ay1 && ay1 < by2 && by2 <= ay2) {
                int rem = (bx2 - bx1) * (by2 - ay1);
                return a1 + a2 - rem;
            }
            else if (ay1 <= by1 && by1 < ay2 && ay2 <= by2) {
                int rem = (bx2 - bx1) * (ay2 - by1);
                return a1 + a2 - rem;
            }
        }
        if (ay1 <= by1 && by2 <= ay2) {
            if (bx1 <= ax1 && ax1 < bx2 && bx2 <= ax2) {
                int rem = (bx2 - ax1) * (by2 - by1);
                return a1 + a2 - rem;
            }
            else if (ax1 <= bx1 && bx1 < ax2 && ax2 <= bx2) {
                int rem = (ax2 - bx1) * (by2 - by1);
                return a1 + a2 - rem;
            }
        }
        // Case 4 : inside one another 
        if (bx1 <= ax1 && ax2 <= bx2 && by1 <= ay1 && ay2 <= by2) {
            return a2;
        }
        if (ax1 <= bx1 && bx2 <= ax2 && ay1 <= by1 && by2 <= ay2) {
            return a1;
        }
        if (ax1 <= bx1 && bx2 <= ax2 && by1 <= ay1 && ay2 <= by2) {
            int rem = (bx2 - bx1) * (ay2 - ay1);
            return a1 + a2 - rem;
        }
        if (bx1 <= ax1 && ax2 <= bx2 && ay1 <= by1 && by2 <= ay2) {
            int rem = (ax2 - ax1) * (by2 - by1);
            return a1 + a2 - rem;
        }
        return 0;
    }
};