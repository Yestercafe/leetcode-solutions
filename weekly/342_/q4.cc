class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt_one = count(nums.begin(), nums.end(), 1);
        if (cnt_one) {
            return n - cnt_one;
        }

        vector<int> prev, f(n);
        prev = nums;
        int ans = 0;
        for (int d = 2; d <= n; ++d) {
            for (int i = 0; i + d - 1 < n; ++i) {
                f[i] = gcd(nums[i + d - 1], prev[i]);
                if (f[i] == 1) {
                    ans = d;
                    break;
                }
            }
            if (ans) break;
            for (auto a : f) {
                cout << a << ' ';
            }
            cout << endl;
            f.swap(prev);
        }

        if (!ans) return -1;
        --ans;
        ans += n - 1;
        return ans;
    }
};

