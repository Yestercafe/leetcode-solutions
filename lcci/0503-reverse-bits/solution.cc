class Solution {
    int stats(unsigned n) {
        int ans = 1;
        int cnt = 0;
        while (n != 0) {
            if (n % 2) ++cnt;
            else {
                ans = max(ans, cnt);
                cnt = 0;
            }
            n /= 2;
        }
        ans = max(ans, cnt);
        return ans;
    }
public:
    int reverseBits(int num) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            auto n = static_cast<unsigned>(num | (1 << i));
            ans = max(ans, stats(n));
        }
        return ans;
    }
};

