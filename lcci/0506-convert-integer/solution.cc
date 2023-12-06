class Solution {
public:
    int convertInteger(int a_, int b_) {
        unsigned a = static_cast<unsigned>(a_);
        unsigned b = static_cast<unsigned>(b_);
        if (a > b) swap(a, b);
        int ans = 0;
        while (b != 0) {
            if (a % 2 != b % 2) {
                ++ans;
            }
            a /= 2;
            b /= 2;
        }
        return ans;
    }
};

