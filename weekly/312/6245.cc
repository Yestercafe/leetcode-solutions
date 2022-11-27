class Solution {
public:
    int pivotInteger(int n) {
        if (n == 1) return 1;
        int all_sum = (n + 1) * n / 2;
        // cout << all_sum << endl;
        int sum = 0;
        for (int a = 1; a <= n; ++a) {
            sum += a;
            if (sum == all_sum + a - sum) return a;
            else if (sum > all_sum + a - sum) return -1;
        }
        return -1;
    }
};
