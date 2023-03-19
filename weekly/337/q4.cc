class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        if (value == 1) {
            return nums.size();
        }
        unordered_map<int, int> cnt;
        for (auto& a : nums) {
            if (a >= 0) a %= value;
            else {
                a += (-a) / value * value + value;
                a %= value;
            }
            ++cnt[a];
        }
        int n = nums.size();
        int minn = n;
        for (int i = 0; i < value; ++i) {
            int exact = n / value;
            if (i < n - n / value * value) {
                ++exact;
            }
            if (cnt[i] < exact) {
                minn = min(minn, i + cnt[i] * value);
            }
        }
        return minn;
    }
};

