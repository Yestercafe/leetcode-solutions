class Solution {
    using i64 = long long;
public:
    int makeTheIntegerZero(i64 num1, i64 num2) {
        for (i64 t = 1; t < 100; ++t) {
            i64 f = num1 - t * num2;
            if (f <= 0) break;
            int bit_cnt = __builtin_popcountll(f);

            if (bit_cnt <= t && t <= f) {
                return t;
            }
        }
        
        return -1;
    }
};

