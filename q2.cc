class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy) {
            if (t == 0) return true;
            if (t == 1) return false;
            else return true;
        }
        if (sx == fx) {
            int dis = abs(fy - sy);
            if (t < dis) return false;
            return true;
        }
        if (sy == fy) {
            int dis = abs(fx - sx);
            if (t < dis) return false;
            return true;
        }

        int disX = abs(fx - sx);
        int disY = abs(fy - sy);
        int minReachT = max(disX, disY);
        if (t < minReachT) return false;
        return true;
    }
};
