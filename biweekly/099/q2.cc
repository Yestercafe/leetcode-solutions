class Solution {
public:
    long long coloredCells(int n) {
        if (n == 1) return 1;
        long long ans = (long long) (2 * n - 1) * (2 * n - 1);
        long long minus = 4 * (long long) n * (n - 1) / 2;
        return ans - minus;
    }
};

