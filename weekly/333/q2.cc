class Solution {
public:
    int minOperations(int n) {
        int cnt = 0, con = 0;
        while (n != 0) {
            if (n % 2) {
                ++con;
            } else {
                if (con == 1) {
                    ++cnt;
                    con = 0;
                } else if (con > 1) {
                    ++cnt;
                    con = 1;
                }
            }
            n /= 2;
        }
        if (con == 1) ++cnt;
        else if (con > 1) cnt += 2;
        return cnt;
    }
};

