class Solution {
public:
    int multiply(int a, int b) {
        if (a < b) swap(a, b);
        if (b == 0) return 0;
        if (b == 1) return a;
        int ans = 0;
        if (b % 2) ans += a;
        ans += multiply(a * 2, b / 2);
        return ans;
    }
};

